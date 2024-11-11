/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:53:26 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/13 16:20:38 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	res;
	int	i;
	int	minus;

	res = 0;
	i = 0;
	minus = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v'
		|| str [i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (minus % 2 == 0)
		return (res);
	return (res = -res);
}
/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "   ---++-12asd3456123";
	int	val = ft_atoi(str);
	printf("%d", val);
	return (0);
}
*/
