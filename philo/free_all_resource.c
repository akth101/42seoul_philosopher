/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_resource.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 04:34:30 by seongjko          #+#    #+#             */
/*   Updated: 2024/04/19 23:13:09 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	free_all_resource(t_share *resource)
{
	int	i;

	i = -1;
	while (++i < resource->philo_cnt)
		free(resource->solo_ary[i]);
	free(resource->solo_ary);
	free(resource->philo_id_ary);
	free(resource->fork_ary);
	free(resource->eating_cnt_ary);
	free(resource->last_eat_ary);
	free(resource->fork_mutex_ary);
	free(resource->dead_mutex);
	free(resource->start_line_mutex);
	free(resource->printf_mutex);
	free(resource->eating_mutex);
	free(resource);
	return ;
}
