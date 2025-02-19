/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_init_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:32:51 by lhaas             #+#    #+#             */
/*   Updated: 2025/02/12 17:26:16 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next_index_d(t_stack *stack, int pivot)
{
	int	i;
	int	size;
	int	idx;

	i = 0;
	size = stack->size;
	while (i < size)
	{
		idx = (stack->head + i) % stack->capacity;
		if (stack->arr[idx].rank >= pivot)
			return (i);
		i++;
	}
	return (-1);
}

int	has_bigger_than_pivot_d(t_stack *stack, int pivot)
{
	int	i;
	int	count;

	i = stack->head;
	count = 0;
	while (count < stack->size)
	{
		if (stack->arr[i].rank > pivot)
			return (1);
		i = (i + 1) % stack->capacity;
		count++;
	}
	return (0);
}

void	handle_moves_d(t_stack *stack_a, t_stack *stack_b, int pivot,
		int *moves)
{
	int	next_index;

	if (stack_b->arr[stack_b->head].rank >= pivot)
	{
		push(stack_a, pop(stack_b));
		(*moves)++;
		ft_printf("pa\n");
		return ;
	}
	next_index = find_next_index_d(stack_b, pivot);
	if (next_index != -1)
	{
		if (next_index <= stack_b->size / 2)
		{
			rotate(stack_b);
			ft_printf("rb\n");
		}
		else
		{
			reverse_rotate(stack_b);
			ft_printf("rrb\n");
		}
		(*moves)++;
	}
}

void	partition_init_b(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int	original_size;
	int	moves;
	int	i;

	original_size = stack_b->size;
	moves = 0;
	i = 0;
	while (i < original_size)
	{
		if (is_strictly_sequential_desc(stack_b, stack_b->size))
			return ;
		if (has_bigger_than_pivot_d(stack_b, pivot))
		{
			handle_moves_d(stack_a, stack_b, pivot, &moves);
		}
		if (moves == original_size)
			break ;
		i++;
	}
}
