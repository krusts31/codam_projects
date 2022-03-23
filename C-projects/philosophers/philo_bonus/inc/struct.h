/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/29 17:35:33 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/13 18:35:35 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>
# include <semaphore.h>

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
	int					id;
	char				*print_msg;
	struct timeval		*time_since_simulation_start;
	struct timeval		start;
	struct timeval		end;
	struct timeval		time_of_last_meal;
	struct timeval		curent_time;
	double				time_stamp;
	double				delta;
	double				time_between_meals;
	double				time_of_death;
	int					index;
	int					sleep_index;
	int					time_to_eat;
	int					time_to_die;
	int					time_to_sleep;
	int					times_to_eat;
	sem_t				*printing_semaphore;
	sem_t				*forks;
	sem_t				*kill_all;
	pid_t				*processes;
	pthread_t			monitoring_thread;
	t_programm_args		program_args;
	int					philosopher_cnt;
}	t_philosopher;

typedef struct s_main_thread
{
	t_programm_args	programm_args;
	t_philosopher	*philosophers;
	pid_t			*processes;
	sem_t			*printing_semaphore;
	sem_t			*forks;
	sem_t			*kill_all;
	sem_t			*start_semaphore;
	struct timeval	*time_since_simulation_start;
	int				processes_spawned;
}	t_main_process;

typedef void	(t_exit_simulation)(t_philosopher *philosopher);
typedef void	*(*t_simulation_func)(t_philosopher *philosopher);

#endif
