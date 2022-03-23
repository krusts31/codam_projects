/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   functions.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 00:57:50 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 19:49:29 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "struct.h"

bool	is_template_valid(t_main_thread *main);
bool	is_template_alloced(t_main_thread *template);
bool	is_even(int philosopher_id);

int		alloc_heap_data(t_main_thread *template);

bool	are_muteces_destroyed(t_main_thread *template);
bool	are_all_done(t_main_thread *template);
int		set_philosophers(t_main_thread *template, int index);
void	*set_to_state(t_main_thread *template,
			int index,
			int set_philosophers,
			enum e_philosopher_state philsopher_state);

/*
 *	functions used by set_philospher to init a philospher struct
 */

void	*make_threads(t_main_thread *template, int index);
int		join_exited_thread(t_main_thread *template,
			int index,
			int joind_threads);

void	*simulation(void *arg);

void	set_time_to_eat(t_main_thread *template, int index);
void	set_times_to_eat(t_main_thread *template, int index);
void	set_time_to_die(t_main_thread *template, int index);
void	set_time_to_sleep(t_main_thread *template, int index);
void	set_current_time_locks(t_main_thread *template, int index);
void	set_right_fork(t_main_thread *template, int index);
void	set_left_fork(t_main_thread *template, int index);
void	set_left_fork(t_main_thread *template, int index);
void	set_philosopher_state_lock(t_main_thread *template, int index);
void	set_thread_state_lock(t_main_thread *template, int index);
void	set_thread_to_exited(t_philosopher *philosopher);
void	set_current_time(t_main_thread *template, int index);
void	set_time_of_last_meal_lock(t_main_thread *template, int index);
void	set_times_to_eat_lock(t_main_thread *template, int index);
void	set_of_last_meal(t_main_thread *template, int index);
void	set_current_time(t_main_thread *template, int index);
void	set_state(t_main_thread *template, int index);
void	set_printing_lock(t_main_thread *template, int index);
void	set_time_since_simulation_started(t_main_thread *template, int index);
void	set_philosopher_state(t_main_thread *template, int index);
void	set_philosopher_time_of_death(t_main_thread *template, int index);

int		init_muteces(t_main_thread *template);
void	init_is_alive_locks(t_main_thread *template);
void	init_printing_lock(t_main_thread *template);

void	*ft_calloc(size_t nmemb, size_t size);

void	*update_time(t_philosopher *philo);
void	*set_delta_ms(t_philosopher *philo);
void	*is_done_sleeping(t_philosopher *philo);
void	*init_time(t_philosopher *philo);
void	*ft_usleep(t_philosopher *philo);
void	*reset_index(t_philosopher *philo);

int		free_template(t_main_thread *template);
void	destroy_muteces(t_main_thread *template, int index);

void	*ft_sleep(t_philosopher *philosopher);

void	*set_time_stamp(t_philosopher *philosopher);
void	*print_status(t_philosopher *philosopher);
void	print_death(t_main_thread *template, int index);

void	*eating(t_philosopher *philosopher);
void	*set_eating(t_philosopher *philosopher);
void	*eating(t_philosopher *philosopher);
void	*set_sleeping(t_philosopher *philosopher);
void	*sleeping(t_philosopher *philosopher);
void	*set_thinking(t_philosopher *philosopher);
void	*thinking(t_philosopher *philosopher);

void	*take_forks(t_philosopher *philosopher);
void	*let_go_forks(t_philosopher *philosopher);

void	*failed_to_sleep(t_philosopher *philo);
void	*failed_to_get_time(t_philosopher *philo);
void	*failed_to_unlock_mutex(t_philosopher *philo);
void	*failed_to_lock_mutex(t_philosopher *philo);
int		failed_to_lock_mutex_ulock(t_philosopher *philosopher);

void	*exit_ft_sleep(t_philosopher *philosopher);

void	*reset_index_philo(t_philosopher *philosopher);

bool	is_template_inited(t_main_thread *template, int index);
bool	is_template_alloced(t_main_thread *template);

int		monitoring_thread(t_main_thread *template, int index);

void	*set_take_forks(t_philosopher *philosopher);

void	*reset_time_between_meals(t_philosopher *philosopher);
double	subtract_time_in_ms(struct timeval x, struct timeval y);
void	*set_time_between_meals(t_philosopher *philo);
bool	is_starved(t_philosopher *philo);
void	*philosopher_starved(t_philosopher *philo);

void	*philosopher_is_dead(t_philosopher *philo);
void	*failed_to_creat_thread(t_philosopher *philo);
void	unlock_all_forks(t_main_thread *template, int index);

void	*eat_for_given_time(t_philosopher *philo);
void	*sleep_for_given_time(t_philosopher *philo);

void	*is_done_sleeping(t_philosopher *philo);
void	*is_done_eating(t_philosopher *philo);

void	*is_simulation_done(t_philosopher *philosopher);
void	*simulation_done(t_philosopher *philo);
double	get_time_diff_in_ms(struct timeval end, struct timeval start);

void	*wait_for_threads(t_philosopher *philosopher);

void	*debug_mutex_lock(t_philosopher *philosopher, pthread_mutex_t *lock);
void	set_id(t_main_thread *template, int index);
void	set_index(t_main_thread *template, int index);

void	set_programm_args(t_main_thread *template, int index);

void	*odd_philo(t_philosopher *philosopher);
void	*even_philo(t_philosopher *philosopher);
bool	is_philosopher_dead(t_philosopher *philosopher);
void	*reset_index_sim(t_philosopher *philosopher);

void	*eating_sleeping_thinking(t_philosopher *philosopher,
		int start_with_sleeping);
int		alloc_and_init_muteces(t_main_thread *template);
void	*philosopher_died(t_philosopher *philosopher);
#endif
