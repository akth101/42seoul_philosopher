/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 00:03:57 by seongjko          #+#    #+#             */
/*   Updated: 2024/04/19 23:43:05 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	eating_time(t_philo *solo)
{
	int	eat_stt_time;

	if (check_is_someone_dead(solo) == DIE)
	{
		put_down_fork_before_finish(solo);
		return (DIE);
	}
	timestamp(solo, EAT);
	eat_stt_time = get_current_time();
	pthread_mutex_lock(solo->eating_mutex);
	*(solo->last_eat) = eat_stt_time;
	*(solo->eating_cnt) += 1;
	pthread_mutex_unlock(solo->eating_mutex);
	while (get_current_time() - eat_stt_time < solo->eat)
	{
		if (check_is_someone_dead(solo) == DIE)
		{
			put_down_fork_before_finish(solo);
			return (DIE);
		}
		usleep(200);
	}
	return (NO_DIE);
}
