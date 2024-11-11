/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:30:17 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/22 16:23:04 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	i = 0;
	size = max - min;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	*range = (int *) malloc((max - min) * sizeof(int));
	while (min < max)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (size);
}
/*
#include <stdio.h>
int     main(void)
{
	int *pointer;
        int **range;
	range = &pointer;
        int min = -123213100;
        int max = 10123210;
	printf("%d", ft_ultimate_range (range, min, max));

        return (0);
}
*/
