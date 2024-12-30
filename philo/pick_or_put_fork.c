/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_or_put_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:52:19 by seongjko          #+#    #+#             */
/*   Updated: 2024/04/19 02:40:17 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	pick_up_fork(t_philo *solo)
{
	pthread_mutex_lock(solo->left_mutex);
	*(solo->left_fork) = 1;
	pthread_mutex_lock(solo->right_mutex);
	*(solo->right_fork) = 1;
	if (check_is_someone_dead(solo) == DIE)
	{
		*(solo->right_fork) = 0;
		pthread_mutex_unlock(solo->right_mutex);
		*(solo->left_fork) = 0;
		pthread_mutex_unlock(solo->left_mutex);
		return (DIE);
	}
	return (NO_DIE);
}

int	put_down_fork(t_philo *solo)
{
	*(solo->right_fork) = 0;
	pthread_mutex_unlock(solo->right_mutex);
	*(solo->left_fork) = 0;
	pthread_mutex_unlock(solo->left_mutex);
	if (check_is_someone_dead(solo) == DIE)
		return (DIE);
	return (NO_DIE);
}

void	put_down_fork_before_finish(t_philo *solo)
{
	*(solo->right_fork) = 0;
	pthread_mutex_unlock(solo->right_mutex);
	*(solo->left_fork) = 0;
	pthread_mutex_unlock(solo->left_mutex);
	return ;
}
