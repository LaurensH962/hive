/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:39:11 by lhaas             #+#    #+#             */
/*   Updated: 2024/10/31 13:24:05 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = c;
		p++;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
   int arr[10];
   ft_memset(arr, 0, sizeof(arr));

   printf("Array after memset(): ");
   for (int i = 0; i < 10; i++) {
       printf("%d ", arr[i]);
   }
   printf("\n");

   return 0;
}
*/
