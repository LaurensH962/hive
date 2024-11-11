/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:06:05 by lhaas             #+#    #+#             */
/*   Updated: 2024/10/31 12:46:05 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <strings.h>
int	main(void)
{
	int i = 9;
	char s[]= "erase me not me";
	ft_bzero(s, i);
	printf("%s\n", s);
	printf("%s\n",s + 8);
	return (0);
}
*/
