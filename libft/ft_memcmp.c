/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:41:35 by lhaas             #+#    #+#             */
/*   Updated: 2024/10/31 13:11:40 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*t;

	p = (unsigned char *)s1;
	t = (unsigned char *)s2;
	while (n > 0)
	{
		if (*p != *t)
			return (*p - *t);
		n--;
		p++;
		t++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[] = "123456";
	char	str2[] = "1234567";
	int		result;

	result = ft_memcmp(str1, str2, 10);
	if (result < 0)
	{
		printf("First is less than second.\n");
	}
	else if (result == 0)
	{
		printf("First is equal to second.\n");
	}
	else
	{
		printf("First is greater than second.\n");
	}
	return (0);
}
*/
