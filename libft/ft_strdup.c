/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:11:56 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/08 10:15:28 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	len;

	len = ft_strlen(s) + 1;
	p = (char *)malloc(len);
	if (p == NULL)
		return (NULL);
	if (p)
		ft_memcpy(p, s, len);
	return (p);
}
/*
#include <stdio.h>

int	main(void)
{
	char	source[] = "Wow";
	char	*target;

	target = ft_strdup(source);
	printf("%s\n", target);
	return (0);
}
*/
