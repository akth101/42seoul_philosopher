/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:44:22 by seongjko          #+#    #+#             */
/*   Updated: 2024/04/19 02:38:14 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	fork_handler(t_philo *solo)
{
	while (1)
	{
		if (pick_up_fork(solo) == DIE)
			return (DIE);
		if (eating_time(solo) == DIE)
			return (DIE);
		if (put_down_fork(solo) == DIE)
			return (DIE);
		if (sleeping_time(solo) == DIE)
			return (DIE);
		if (thinking_time(solo) == DIE)
			return (DIE);
	}
	return (NO_DIE);
}
