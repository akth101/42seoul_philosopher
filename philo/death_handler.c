/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:31:10 by seongjko          #+#    #+#             */
/*   Updated: 2024/04/19 23:43:21 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_is_someone_dead(t_philo *solo)
{
	pthread_mutex_lock(solo->dead_mutex);
	if (*(solo->is_someone_dead) == 1)
	{
		pthread_mutex_unlock(solo->dead_mutex);
		return (DIE);
	}
	pthread_mutex_unlock(solo->dead_mutex);
	return (NO_DIE);
}
