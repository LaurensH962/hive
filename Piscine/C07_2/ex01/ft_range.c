/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:48:16 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/22 16:27:11 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	temp;

	temp = 0;
	if (min >= max)
		return (NULL);
	range = (int *) malloc ((max - min) * sizeof(int));
	if (range == NULL)
		return (NULL);
	while (min < max)
	{
		range[temp] = min;
		min++;
		temp++;
	}
	return (range);
}
/*
#include <stdio.h>
int	main(void)
{
	int min = -100;
	int max = 100;
	printf("%d", ft_range (min, max));
	return (0);
}*/
