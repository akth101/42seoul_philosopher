/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_watcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 00:23:44 by seongjko          #+#    #+#             */
/*   Updated: 2024/04/19 22:43:42 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	yes_died(t_share *resource, int i)
{
	int	current_time;
	int	how_long;

	current_time = get_current_time();
	how_long = current_time - resource->start_time;
	pthread_mutex_lock(resource->dead_mutex);
	resource->is_someone_dead = 1;
	pthread_mutex_unlock(resource->dead_mutex);
	pthread_mutex_lock(resource->printf_mutex);
	printf("%d %d died\n", how_long, i + 1);
	pthread_mutex_unlock(resource->printf_mutex);
	return ;
}

int	is_someone_died(t_share *resource, int i)
{
	int	current_time;

	current_time = get_current_time();
	pthread_mutex_lock(resource->eating_mutex);
	if (current_time - resource->last_eat_ary[i] >= resource->die)
	{
		pthread_mutex_unlock(resource->eating_mutex);
		yes_died(resource, i);
		return (YES);
	}
	pthread_mutex_unlock(resource->eating_mutex);
	return (NO);
}

int	check_if_all_philo_ate(t_share *resource)
{
	int	i;

	i = 0;
	while (i < resource->philo_cnt)
	{
		pthread_mutex_lock(resource->eating_mutex);
		if (resource->eating_cnt_ary[i] < resource->must_eat_cnt)
		{
			pthread_mutex_unlock(resource->eating_mutex);
			return (NO);
		}
		pthread_mutex_unlock(resource->eating_mutex);
		i++;
	}
	pthread_mutex_lock(resource->dead_mutex);
	resource->is_someone_dead = 1;
	pthread_mutex_unlock(resource->dead_mutex);
	return (YES);
}

int	check_if_someone_die(t_share *resource)
{
	int	i;

	i = -1;
	while (++i < resource->philo_cnt)
	{
		if (is_someone_died(resource, i) == YES)
			return (YES);
	}
	return (NO);
}

void	main_thread_is_watching(t_share *resource)
{
	if (resource->must_eat_cnt != NO_INPUT)
	{
		while (1)
		{
			if (check_if_all_philo_ate(resource) == YES || \
			check_if_someone_die(resource) == YES)
				break ;
			usleep(100);
		}
	}
	else
	{
		while (1)
		{
			if (check_if_someone_die(resource) == YES)
				break ;
			usleep(100);
		}
	}
	return ;
}
