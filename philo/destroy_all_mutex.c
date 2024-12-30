/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all_mutex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 04:56:06 by seongjko          #+#    #+#             */
/*   Updated: 2024/04/18 07:43:58 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	destroy_all_mutex(t_share *resource)
{
	int	i;

	i = -1;
	while (++i < resource->philo_cnt)
		pthread_mutex_destroy(&resource->fork_mutex_ary[i]);
	pthread_mutex_destroy(resource->dead_mutex);
	pthread_mutex_destroy(resource->start_line_mutex);
	pthread_mutex_destroy(resource->printf_mutex);
	pthread_mutex_destroy(resource->eating_mutex);
	return ;
}
