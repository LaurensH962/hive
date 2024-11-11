/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:19:43 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/11 11:14:30 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	i = 0;
	cc = (char)c;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*str = "Welcome to My world";
	char		ch;
	char		*p;

	ch = 'r';
	p = ft_strchr(str, ch);
	if (p != NULL)
	{
		printf("String starting from '%c' is: %s\n", ch, p);
	}
	else
	{
		printf("Character '%c' not found in the string.\n", ch);
	}
	return (0);
}
*/
