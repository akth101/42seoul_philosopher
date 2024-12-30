/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:45:24 by seongjko          #+#    #+#             */
/*   Updated: 2024/04/19 23:43:34 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char *argv[])
{
	t_share	*resource;

	resource = (t_share *)malloc(sizeof(t_share));
	if (is_argument_valid(resource, argc, argv) == NO)
		return (0);
	if (!resource->philo_cnt)
	{
		printf("There is no any philosopher\n");
		return (0);
	}
	create_philosopher(resource);
	destroy_all_mutex(resource);
	free_all_resource(resource);
	return (0);
}
