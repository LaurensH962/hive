/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:49:13 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/11 13:37:54 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	all;

	all = nmemb * size;
	if (nmemb != 0 && size != 0 && (size != (all / nmemb)))
		return (NULL);
	p = (void *)malloc(all);
	if (p)
		ft_bzero(p, all);
	return (p);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	long	*number;

	// initialize number with null
	number = NULL;
	if (number != NULL)
	{
		printf("Allocated 10 long integers.\n");
	}
	else
	{
		printf("Can't allocate memory.\n");
	}
	// allocating memory of a number
	number = (long *)ft_calloc(10, sizeof(long));
	if (number != NULL)
	{
		printf("Allocated 10 long integers.\n");
	}
	else
	{
		printf("\nCan't allocate memory.\n");
	}
	// free the allocated memory
	free(number);
	return (0);
}

 */
