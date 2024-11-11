/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:44:20 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/11 11:09:02 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
/*
#include <stdio.h>

int	main(void)
{
	char		dst[20];
	const char	*src = "Fantastico";
	size_t		dstsize;
	size_t		len;

	dstsize = 15;
	len = ft_strlcpy(dst, src, dstsize);
	printf("Copied '%s' into '%s', length %zu\n", src, dst, len);
	return (0);
}
*/
