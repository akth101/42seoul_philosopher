/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:15:40 by seongjko          #+#    #+#             */
/*   Updated: 2024/04/19 23:44:09 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	thinking_time(t_philo *solo)
{
	if (check_is_someone_dead(solo) == DIE)
		return (DIE);
	timestamp(solo, THINK);
	return (NO_DIE);
}
