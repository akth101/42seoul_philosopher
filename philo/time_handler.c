/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:32:19 by seongjko          #+#    #+#             */
/*   Updated: 2024/04/19 22:50:19 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	timestamp(t_philo *solo, int stamp)
{
	int	current_time;
	int	how_long;

	current_time = get_current_time();
	how_long = current_time - solo->start_time;
	pthread_mutex_lock(solo->printf_mutex);
	if (stamp == EAT)
	{
		printf("%d %d has taken a fork\n", how_long, solo->philo_num);
		printf("%d %d has taken a fork\n", how_long, solo->philo_num);
		printf("%d %d is eating\n", how_long, solo->philo_num);
	}
	else if (stamp == SLEEP)
		printf("%d %d is sleeping\n", how_long, solo->philo_num);
	else if (stamp == THINK)
		printf("%d %d is thinking\n", how_long, solo->philo_num);
	pthread_mutex_unlock(solo->printf_mutex);
	return ;
}
