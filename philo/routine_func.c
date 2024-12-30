/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:33:34 by seongjko          #+#    #+#             */
/*   Updated: 2024/04/19 02:50:15 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	odd_or_even(t_philo *solo)
{
	if (solo->philo_cnt == 1)
	{
		if (only_one_philo(solo) == DIE)
			return (DIE);
	}
	if (solo->philo_cnt != 1 && solo->philo_num % 2 != 0)
	{
		timestamp(solo, THINK);
		usleep((solo->eat / 2) * 1000);
	}
	if (fork_handler(solo) == DIE)
		return (DIE);
	return (NO_DIE);
}

void	*routine_func(void *arg)
{
	t_philo		*solo;

	solo = (t_philo *)arg;
	pthread_mutex_lock(solo->start_line_mutex);
	pthread_mutex_unlock(solo->start_line_mutex);
	if (odd_or_even(solo) == DIE)
		return (NULL);
	return (NULL);
}
