/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   functions.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 00:57:50 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/13 20:23:09 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "struct.h"

bool	is_even(int philosopher_id);

int		allocatet_arg_for_thread(t_main_process *template);

bool	are_all_done(t_main_process *template);

/*
 *	functions used by set_philospher to init a philospher struct
 */

int		make_processes(t_main_process *template);

void	*simulation(void *arg);

void	set_curent_time(t_philosopher *philo);
void	*reset_index(t_philosopher *philo);

void	*ft_sleep(t_philosopher *philosopher);

void	*set_time_stamp(t_philosopher *philosopher);
void	*print_status(t_philosopher *philosopher);
void	print_death(t_philosopher *template);

void	eating(t_philosopher *philosopher);
void	set_eating(t_philosopher *philosopher);
void	set_sleeping(t_philosopher *philosopher);
void	sleeping(t_philosopher *philosopher);
void	set_thinking(t_philosopher *philosopher);
void	thinking(t_philosopher *philosopher);

void	take_forks(t_philosopher *philosopher);
void	let_go_forks(t_philosopher *philosopher);

void	*exit_ft_sleep(t_philosopher *philosopher);

void	*reset_index_philo(t_philosopher *philosopher);

int		monitoring_thread(t_main_process *template, int index);

void	set_take_forks(t_philosopher *philosopher);

void	*reset_time_between_meals(t_philosopher *philosopher);
double	subtract_time_in_ms(struct timeval x, struct timeval y);
void	*set_time_between_meals(t_philosopher *philo);
void	set_time_of_death(t_philosopher *philosopher);
bool	is_starved(t_philosopher *philo);
void	*philosopher_starved(t_philosopher *philo);

void	*philosopher_is_dead(t_philosopher *philo);
void	*failed_to_creat_thread(t_philosopher *philo);

void	*eat_for_given_time(t_philosopher *philo);
void	*sleep_for_given_time(t_philosopher *philo);

void	*is_done_sleeping(t_philosopher *philo);
void	*is_done_eating(t_philosopher *philo);

void	*is_simulation_done(t_philosopher *philosopher);
void	*simulation_done(t_philosopher *philo);
double	get_time_diff_in_ms(struct timeval end, struct timeval start);

void	*wait_for_threads(t_philosopher *philosopher);

/*
 *	utils
 */

void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);

/*
**	wrapper funcitons
*/

sem_t	*new_semaphore(const char *name, const int value);
void	*malloc_wrapper(const char *name, const int size, const int value);

void	kill_all_philosophers(t_main_process *philosopher, pid_t pid);

void	set_philosophers(t_main_process *template);
void	set_program_args(t_main_process *template, int index);
void	set_printing_semaphore(t_main_process *template, int index);
void	set_pid(t_main_process *template, int index, int value);
void	set_id(t_main_process *template, int index);
void	set_time_since_simulation_start(t_main_process *template, int index);
void	set_kill_all(t_main_process *template, int index);
void	set_forks(t_main_process *template, int index);

/*
 *	monitoring_thread
 */

void	*creat_monithoring_thread(t_philosopher	*philosopher);
void	*monitor_philosopher(void *arg);
void	failed_to_create_thread(void);

void	alloc_processes(t_main_process *template);

/*
**	printing
*/

void	stop_printing(t_philosopher *philosopher);
void	start_priniting(t_philosopher *philosopher);

/*
**	ft_usleep
*/

void	*update_time(t_philosopher *philo);
void	*set_delta_ms(t_philosopher *philo);
void	*is_done_sleeping(t_philosopher *philo);
void	*init_time(t_philosopher *philo);
void	*ft_usleep(t_philosopher *philo);

/*
**		the loop of eating sleeping thinking call
*/

void	start_simulation_even(t_philosopher *philosopher);
void	start_simulation_odd(t_philosopher *philosopher);

void	wait_for_processes(t_main_process *template);
#endif
