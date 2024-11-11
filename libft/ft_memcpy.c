/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:21:24 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/08 13:29:39 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (cdest);
}
/*
#include <stdio.h>
#include <string.h>

int main ()
{
   const char src[50] = "BYEEE";
   char dest[50];

   strcpy(dest,"Heloooo!!");
   printf("Before memcpy dest = %s\n", dest);
   ft_memcpy(dest, src, strlen(src) + 1);
   printf("After memcpy dest = %s\n", dest);
   return(0);
}
*/
