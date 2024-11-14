/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:06:51 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/14 11:25:44 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	res;
	int			idx;

	sign = 1;
	res = 0;
	idx = 0;
	while (nptr[idx] == ' ' || nptr[idx] == '\n' || nptr[idx] == '\t'
		|| nptr[idx] == '\v' || nptr[idx] == '\f' || nptr[idx] == '\r')
		idx++;
	if (nptr[idx] == '-' || nptr[idx] == '+')
	{
		if (nptr[idx++] == '-')
			sign = -1;
	}
	while (nptr[idx] >= '0' && nptr[idx] <= '9')
	{
		res = 10 * res + (nptr[idx++] - '0');
	}
	return (res * sign);
}

 #include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	s[] = "2312323999888213123213123";

	printf("%d\n", ft_atoi(s));
	printf("%d\n", atoi(s));
	return (0);
}

