/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:46:22 by seongjko          #+#    #+#             */
/*   Updated: 2024/04/19 23:10:01 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef enum e_enum {
	YES,
	NO,
	EAT,
	SLEEP,
	THINK,
	INVALID = -1,
	NO_INPUT = -2,
	DIE,
	NO_DIE,
	ONLY_CHECK,
	CHECK_AND_PRINT,
	NONE,
	WAIT,
	GOT_TWO_FORKS
}	t_eum;

typedef struct s_philo {
	int				philo_num;
	int				philo_cnt;
	int				die;
	int				eat;
	int				sleep;
	int				must_eat_cnt;
	pthread_mutex_t	*dead_mutex;
	pthread_mutex_t	*printf_mutex;
	pthread_mutex_t	*left_mutex;
	pthread_mutex_t	*right_mutex;
	pthread_mutex_t	*start_line_mutex;
	pthread_mutex_t	*eating_mutex;
	int				*left_fork;
	int				*right_fork;
	int				*eating_cnt;
	int				*is_someone_dead;
	int				start_time;
	int				*last_eat;
}	t_philo;

typedef struct s_share {
	int				philo_cnt;
	int				die;
	int				eat;
	int				sleep;
	int				must_eat_cnt;
	int				is_someone_dead;
	int				start_time;
	pthread_mutex_t	*dead_mutex;
	pthread_mutex_t	*printf_mutex;
	pthread_mutex_t	*fork_mutex_ary;
	pthread_mutex_t	*start_line_mutex;
	pthread_mutex_t	*eating_mutex;
	pthread_t		*philo_id_ary;
	int				*fork_ary;
	int				*eating_cnt_ary;
	int				*last_eat_ary;
	t_philo			**solo_ary;
}	t_share;

int		is_argument_valid(t_share *resource, int argc, char *argv[]);
void	init_resource(t_share *resource);
int		philo_atoi(const char *str);
int		check_str(const char *str);
int		letsgo_atoi(const char *str);
void	*routine_func(void *arg);
int		get_current_time(void);
void	create_philosopher(t_share *resource);
int		check_is_someone_dead(t_philo *solo);
int		death_checker(t_philo *solo, int flag, int stamp);
int		fork_handler(t_philo *solo);
t_philo	*resource_distributor(t_share *resource, int i);
void	fork_distributor(t_share *resource, t_philo *solo, int i);
int		odd_or_even(t_philo *solo);
void	*routine_func(void *arg);
void	timestamp(t_philo *solo, int stamp);
int		get_current_time(void);
void	main_thread_is_watching(t_share *resource);
int		pick_up_fork(t_philo *solo);
int		put_down_fork(t_philo *solo);
void	put_down_fork_before_finish(t_philo *solo);
int		eating_time(t_philo *solo);
int		sleeping_time(t_philo *solo);
int		only_one_philo(t_philo *solo);
void	free_all_resource(t_share *resource);
void	destroy_all_mutex(t_share *resource);
int		thinking_time(t_philo *solo);

#endif 