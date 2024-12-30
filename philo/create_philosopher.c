/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:24:59 by seongjko          #+#    #+#             */
/*   Updated: 2024/04/19 00:51:22 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	finish_all_threads(t_share *resource)
{
	int	i;

	i = -1;
	while (++i < resource->philo_cnt)
		pthread_join(resource->philo_id_ary[i], NULL);
	return ;
}

void	create_philosopher(t_share *resource)
{
	int	i;

	i = -1;
	pthread_mutex_lock(resource->start_line_mutex);
	while (++i < resource->philo_cnt)
	{
		if (pthread_create(&resource->philo_id_ary[i], NULL, \
		routine_func, \
		(void *)resource_distributor(resource, i)))
		{
			printf("failed creating Thread %d\n", i);
			return ;
		}
	}
	pthread_mutex_unlock(resource->start_line_mutex);
	main_thread_is_watching(resource);
	finish_all_threads(resource);
	return ;
}
