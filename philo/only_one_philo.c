/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_one_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 04:13:22 by seongjko          #+#    #+#             */
/*   Updated: 2024/04/19 22:43:42 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	only_one_philo(t_philo *solo)
{
	int	current_time;
	int	how_long;

	pthread_mutex_lock(solo->left_mutex);
	*(solo->left_fork) = 1;
	current_time = get_current_time();
	how_long = current_time - solo->start_time;
	printf("%d %d has taken a fork\n", how_long, solo->philo_num);
	while (1)
	{
		if (check_is_someone_dead(solo) == DIE)
		{
			*(solo->left_fork) = 0;
			pthread_mutex_unlock(solo->left_mutex);
			return (DIE);
		}
		usleep(100);
	}
	return (NO_DIE);
}
