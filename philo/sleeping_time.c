/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:44:22 by seongjko          #+#    #+#             */
/*   Updated: 2024/04/19 01:17:31 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	sleeping_time(t_philo *solo)
{
	int	sleep_stt_time;

	if (check_is_someone_dead(solo) == DIE)
		return (DIE);
	timestamp(solo, SLEEP);
	sleep_stt_time = get_current_time();
	while (get_current_time() - sleep_stt_time < solo->sleep)
	{
		if (check_is_someone_dead(solo) == DIE)
			return (DIE);
		usleep(200);
	}
	return (NO_DIE);
}
