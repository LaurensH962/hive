/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:08:27 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/08 14:36:10 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;

	if (!dest && !src)
		return (NULL);
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	if (csrc < cdest)
	{
		cdest += n - 1;
		csrc += n - 1;
		while (n > 0)
		{
			*cdest = *csrc;
			cdest--;
			csrc--;
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/* #include <stdio.h>

int	main(void)
{
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest;

	// printf("Before: %s\n", dest);
	ft_memmove(dest, src, 8);
	// memmove(dest, src, sizeof (src));
	printf("After: %s\n", dest);
	return (0);
}
*/
/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "Hello, World!";
	char	dest[20];
	char	src2[] = "Hello, World!";
	char	dest2[20];

	// Test case 1: Non-overlapping memory regions
	printf("Test case 1: Non-overlapping memory regions\n");
	memmove(dest, src, strlen(src) + 1);
	printf("Copied string: %s\n", dest);
	ft_memmove(dest2, src2, strlen(src2) + 1);
	printf("Copied string: %s\n", dest2);
	// Test case 2: Overlapping memory regions (source before destination)
	printf("Overlapping memory regions (source before destination)\n");
	memmove(dest + 2, dest, strlen(dest) + 1);
	printf("Copied string: %s\n", dest);
	ft_memmove(dest2 + 2, dest2, strlen(dest2) + 1);
	printf("Copied string: %s\n", dest2);
	// Test case 3: Overlapping memory regions (destination before source)
	printf("Overlapping memory regions (destination before source)\n");
	memmove(dest, dest + 2, strlen(dest) + 1);
	printf("Copied string: %s\n", dest);
	ft_memmove(dest2, dest2 + 2, strlen(dest2) + 1);
	printf("Copied string: %s\n", dest2);
	return (0);
}
 */
