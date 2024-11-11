/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaasn@student.hive.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:14:50 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/02 13:18:03 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	l;
	char	p;

	l = 'N';
	p = 'P';
	if (n >= 0)
	{		
		write (1, &p, 1);
	}
	else
	{
		write (1, &l, 1);
	}
}
/*
int	main(void)
{
	ft_is_negative(1);
	return (0);
*/
