/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:19:27 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/11 12:02:33 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	d_len;
	size_t	s_len;

	if (size == 0 && (!dst || !src))
		return (0);
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (size == 0)
		return (s_len);
	count = 0;
	if (size <= d_len)
		return (s_len + size);
	else if (size > d_len)
	{
		while (count < (size - d_len - 1) && src[count] != '\0')
		{
			dst[d_len + count] = src[count];
			count++;
		}
	}
	dst[d_len + count] = '\0';
	return (d_len + s_len);
}

/* #include <stdio.h>

int	main(void)
{
	char		dest[50] = "hi you ";
	const char	*src;

	// char		dest1[50] = "hi you ";
	src = NULL;
	// len = ft_strlcat (dest, src, nb);
	// printf("%s%s, count:%zu\n",dest, src, len);
	printf("count:%zu\n%s \n\n", ft_strlcat(dest, src, 9), dest);
	// printf("count:%zu\n%s \n\n", strlcat(dest1, src, 9), dest1);
	return (0);
} */
