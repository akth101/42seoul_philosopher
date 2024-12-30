/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_handler_util.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:31:17 by seongjko          #+#    #+#             */
/*   Updated: 2024/04/10 21:48:40 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	letsgo_atoi(const char *str)
{
	int	num;

	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num);
}

int	check_str(const char *str)
{
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	philo_atoi(const char *str)
{
	int	ans;

	if (*str == '-')
	{
		printf("argument cannot be negative\n");
		return (INVALID);
	}
	else if (*str == '+')
		str++;
	if (!check_str(str))
	{
		printf("invalid argument\n");
		return (INVALID);
	}
	ans = letsgo_atoi(str);
	return (ans);
}
