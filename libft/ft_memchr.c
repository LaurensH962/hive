/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:11:43 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/08 12:27:01 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	t;
	size_t			i;

	p = (unsigned char *)s;
	t = c;
	i = 0;
	while (i < n)
	{
		if (*p == t)
			return ((unsigned char *)p);
		p++;
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>


	unsigned char	*p;
	unsigned char	t;
	size_t			i;

	p = (unsigned char *)s;
	t = c;
	i = 0;
	while (*p && i < n)
	{
		if (*p == t)
			return ((unsigned char *)p);
		p++;
		i++;
	}
	return (NULL);

int	main(void)
{
	const char	str[] = "hallo du da";
	const char	ch = 'u';
	char		*ret;

	ret = ft_memchr(str, ch, sizeof(str));
	printf("String after |%c| is - |%s|\n", ch, ret);
	return (0);
}
*/
