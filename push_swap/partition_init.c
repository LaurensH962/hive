/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:32:01 by lhaas             #+#    #+#             */
/*   Updated: 2025/02/12 17:31:23 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next_index_c(t_stack *stack, int pivot)
{
	int	i;
	int	size;
	int	idx;

	size = stack->size;
	i = 0;
	while (i < size)
	{
		idx = (stack->head + i) % stack->capacity;
		if (stack->arr[idx].rank < pivot)
			return (i);
		i++;
	}
	return (-1);
}

int	has_smaller_than_pivot_c(t_stack *stack, int pivot)
{
	int	i;
	int	count;

	i = stack->head;
	count = 0;
	while (count < stack->size)
	{
		if (stack->arr[i].rank < pivot)
			return (1);
		i = (i + 1) % stack->capacity;
		count++;
	}
	return (0);
}

void	handle_moves_c(t_stack *stack_a, t_stack *stack_b, int pivot,
		int *moves)
{
	int	next_index;

	if (stack_a->arr[stack_a->head].rank <= pivot)
	{
		push(stack_b, pop(stack_a));
		(*moves)++;
		ft_printf("pb\n");
		return ;
	}
	next_index = find_next_index_c(stack_a, pivot);
	if (next_index != -1)
	{
		if (next_index <= stack_a->size / 2)
		{
			ft_printf("ra\n");
			rotate(stack_a);
		}
		else
		{
			ft_printf("rra\n");
			reverse_rotate(stack_a);
		}
		(*moves)++;
	}
}

void	partition_init(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int	original_size;
	int	moves;
	int	i;

	original_size = stack_a->size;
	moves = 0;
	i = 0;
	while (i < original_size)
	{
		if (is_strictly_sequential_asc(stack_a, stack_a->size))
			return ;
		if (has_smaller_than_pivot_c(stack_a, pivot))
		{
			handle_moves_c(stack_a, stack_b, pivot, &moves);
		}
		if (moves == original_size)
			break ;
		i++;
	}
}
