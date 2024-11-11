/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:05:17 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/08 13:53:07 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] && i < n) || (s2[i] && i < n))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	int	a;
	int	n;
		char      s1[] = "hellA";
		char      s2[] = "hello";

		a = 1;
		n = 20;
		a = ft_strncmp (s1, s2, n);
		printf("%d",a);
		return (0);
}
*/
