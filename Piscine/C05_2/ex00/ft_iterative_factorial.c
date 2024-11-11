/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:21:19 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/12 13:28:10 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;
	int	i;

	res = 1;
	i = 2;
	if (nb < 0)
		return (0);
	if (nb == 0)
	{
		res = 1;
		return (res);
	}
	while (i <= nb)
	{
		res *= i;
		i++;
	}
	return (res);
}
/*
#include <stdio.h>
int	main(void)
{
	int nb = 5;
	printf("%d", ft_iterative_factorial (nb));
	return (0);
}
*/
