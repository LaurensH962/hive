/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:37:05 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/14 11:20:18 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (2);
	while (i < nb)
	{
		if (nb % i == 0)
			return (ft_find_next_prime (nb + 1));
		i++;
	}
	return (nb);
}
/*
#include <stdio.h>
int     main(void)
{       
        int nb = 74;
        printf("%d",ft_find_next_prime(nb));
        return (0);
}
*/
