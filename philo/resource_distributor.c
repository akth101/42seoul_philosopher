/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource_distributor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:29:13 by seongjko          #+#    #+#             */
/*   Updated: 2024/04/19 23:12:23 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	fork_distributor(t_share *resource, t_philo *solo, int i)
{
	solo->left_mutex = &resource->fork_mutex_ary[i];
	solo->left_fork = &resource->fork_ary[i];
	if (resource->philo_cnt == 1)
	{
		solo->right_mutex = NULL;
		solo->right_fork = NULL;
	}
	else if (i != resource->philo_cnt - 1)
	{
		solo->right_mutex = &resource->fork_mutex_ary[i + 1];
		solo->right_fork = &resource->fork_ary[i + 1];
	}
	else
	{
		solo->right_mutex = &resource->fork_mutex_ary[0];
		solo->right_fork = &resource->fork_ary[0];
	}
	return ;
}

t_philo	*resource_distributor(t_share *resource, int i)
{
	t_philo	*solo;

	solo = (t_philo *)malloc(sizeof(t_philo));
	resource->solo_ary[i] = solo;
	solo->philo_num = i + 1;
	solo->philo_cnt = resource->philo_cnt;
	solo->die = resource->die;
	solo->eat = resource->eat;
	solo->sleep = resource->sleep;
	solo->must_eat_cnt = resource->must_eat_cnt;
	solo->eating_cnt = &(resource->eating_cnt_ary[i]);
	solo->is_someone_dead = &resource->is_someone_dead;
	solo->dead_mutex = resource->dead_mutex;
	solo->start_time = resource->start_time;
	solo->last_eat = &resource->last_eat_ary[i];
	*(solo->last_eat) = resource->start_time;
	solo->start_line_mutex = resource->start_line_mutex;
	solo->printf_mutex = resource->printf_mutex;
	solo->eating_mutex = resource->eating_mutex;
	fork_distributor(resource, solo, i);
	return (solo);
}
