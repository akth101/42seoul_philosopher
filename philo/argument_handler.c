/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:17:59 by seongjko          #+#    #+#             */
/*   Updated: 2024/04/19 23:09:55 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init_ary(t_share *resource)
{
	resource->philo_id_ary = \
	(pthread_t *)malloc(sizeof(pthread_t) * resource->philo_cnt);
	resource->fork_ary = \
	(int *)malloc(sizeof(int) * resource->philo_cnt);
	memset(resource->fork_ary, 0, sizeof(int) * resource->philo_cnt);
	resource->eating_cnt_ary = \
	(int *)malloc(sizeof(int) * resource->philo_cnt);
	memset(resource->eating_cnt_ary, 0, sizeof(int) * resource->philo_cnt);
	resource->last_eat_ary = \
	(int *)malloc(sizeof(int) * resource->philo_cnt);
	resource->solo_ary = \
	(t_philo **)malloc(sizeof(t_philo *) * resource->philo_cnt);
	return ;
}

void	init_mutex(t_share *resource)
{
	int	i;

	resource->fork_mutex_ary = \
	(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * resource->philo_cnt);
	i = -1;
	while (++i < resource->philo_cnt)
		pthread_mutex_init(&resource->fork_mutex_ary[i], NULL);
	resource->dead_mutex = \
	(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(resource->dead_mutex, NULL);
	resource->start_line_mutex = \
	(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(resource->start_line_mutex, NULL);
	resource->printf_mutex = \
	(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(resource->printf_mutex, NULL);
	resource->eating_mutex = \
	(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(resource->eating_mutex, NULL);
	return ;
}

void	init_resource(t_share *resource)
{
	resource->start_time = get_current_time();
	resource->is_someone_dead = 0;
	init_ary(resource);
	init_mutex(resource);
	return ;
}

int	is_argument_valid(t_share *resource, int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
	{
		printf("wrong argument number\n");
		return (NO);
	}
	resource->philo_cnt = philo_atoi(argv[1]);
	resource->die = philo_atoi(argv[2]);
	resource->eat = philo_atoi(argv[3]);
	resource->sleep = philo_atoi(argv[4]);
	if (argc == 6)
		resource->must_eat_cnt = philo_atoi(argv[5]);
	else
		resource->must_eat_cnt = NO_INPUT;
	if (resource->philo_cnt == INVALID || \
		resource->die == INVALID || \
		resource->eat == INVALID || \
		resource->sleep == INVALID || \
		resource->must_eat_cnt == INVALID)
		return (NO);
	init_resource(resource);
	return (YES);
}
