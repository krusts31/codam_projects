/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/29 17:35:33 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 12:26:21 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

enum e_philosopher_state {alive = 0, dead = 1, error = 2, done = 3};
enum e_thread_state {running = 0, exited = 1, joined = 2};
enum e_fork_state {no_forks = 0, both_forks = 1};

/*
**	programm args in order as passed to programm
*/

typedef struct s_programm_args
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_to_eat;
}	t_programm_args;

typedef struct s_philosopher
{
	int							id;
	enum e_thread_state			thread_state;
	enum e_philosopher_state	state;
	enum e_fork_state			fork_state;
	char						*print_msg;
	struct timeval				*time_since_simulation_start;
	struct timeval				start;
	struct timeval				end;
	struct timeval				time_of_last_meal;
	struct timeval				curent_time;
	pthread_mutex_t				*thread_state_lock;
	pthread_mutex_t				*state_lock;
	pthread_mutex_t				*printing_lock;
	pthread_mutex_t				*right_fork;
	pthread_mutex_t				*left_fork;
	pthread_mutex_t				*time_of_last_meal_lock;
	pthread_mutex_t				*current_time_lock;
	pthread_t					thread;
	double						time_stamp;
	double						delta;
	double						time_between_meals;
	double						time_of_death;
	int							index;
	int							sleep_index;
	t_programm_args				program_args;
}	t_philosopher;

/*
**	since only one argument can be passed to simulation
**	we will pass a struct that points
*/

/*
**	there are 6 critical spaces we need to protect with mutexes
**	times_to_eat
**	current_time
**	time_of_last_meal
**	state
**	thread_state
**	stdout
**
********************
**	stdout only sheared amoung spwaned threads so the main thread will not
**	interfeere with this one
*******************
**	thread_state is also just used in on place when a thread exits
**	to know when to join it with the main thread
******************
**	the rest are activly read and writen to by all threads
**/

typedef struct s_main_thread
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*printing_lock;
	pthread_mutex_t	*state_locks;
	pthread_mutex_t	*thread_state_locks;
	pthread_mutex_t	*time_of_last_meal_locks;
	pthread_mutex_t	*current_time_locks;
	t_philosopher	*philosophers;
	t_programm_args	programm_args;
	struct timeval	*time_since_simulation_start;
	int				created_threads;
}	t_main_thread;

typedef void	*(t_exit_simulation)(t_philosopher *philo);
typedef void	*(*t_simulation_func)(t_philosopher *philosopher);

#endif
