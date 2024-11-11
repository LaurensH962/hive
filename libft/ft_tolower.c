/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:46:01 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/08 10:58:02 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
	}
	return (c);
}
/*  #include <stdio.h>

int	main(void)
{
	char	a;
	char	b;
	int 	c;

	a = 'A';
	b = 'b';
	c = '9';
	printf("%c\n%c\n%c\n", ft_tolower(a), ft_tolower(b), ft_tolower(c));
	return (0);
}  */