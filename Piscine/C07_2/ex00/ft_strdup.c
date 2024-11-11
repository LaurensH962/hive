/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:48:16 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/21 10:16:05 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		p;

	len = 0;
	p = 0;
	while (src[len])
	{
		len++;
	}
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	while (p <= len)
	{
		dest[p] = src[p];
		p++;
	}
	dest[p] = '\0';
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*src;

	src = "";
	printf("%s", ft_strdup(src));
	return (0);
}
*/
