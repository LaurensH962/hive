/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:22:25 by lhaas             #+#    #+#             */
/*   Updated: 2025/02/12 18:13:30 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char *argv[], int i)
{
	if (i == 0)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}

void	free_all(t_stack stack_a, t_stack stack_b, char *argv[], int i)
{
	if (i == 0)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	free(stack_a.arr);
	free(stack_b.arr);
}
