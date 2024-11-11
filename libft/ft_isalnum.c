/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:44:59 by lhaas             #+#    #+#             */
/*   Updated: 2024/10/31 12:49:40 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A'
			&& c <= 'Z'))
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	c;
	int		result;

	c = '5';
	result = ft_isalnum(c);
	printf("When %c is passed, return (value is %d\n", c, result));
	c = 'Q';
	result = ft_isalnum(c);
	printf("When %c is passed, return (value is %d\n", c, result));
	c = 'l';
	result = ft_isalnum(c);
	printf("When %c is passed, return (value is %d\n", c, result));
	c = '+';
	result = ft_isalnum(c);
	printf("When %c is passed, return (value is %d\n", c, result));
	return (0);
}
*/
