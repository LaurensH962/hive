/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asc_desc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:02:51 by lhaas             #+#    #+#             */
/*   Updated: 2025/02/07 14:48:40 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_strictly_sequential_desc(t_stack *stack_b, int size)
{
	int	i;
	int	current_index;
	int	next_index;

	if (!stack_b || is_empty(stack_b) || size < 2)
		return (0);
	i = 0;
	while (i < size - 1)
	{
		current_index = (stack_b->head + i) % stack_b->capacity;
		next_index = (stack_b->head + i + 1) % stack_b->capacity;
		if (stack_b->arr[next_index].rank != stack_b->arr[current_index].rank
			- 1)
			return (0);
		i++;
	}
	return (1);
}

int	is_strictly_sequential_asc(t_stack *stack_a, int size)
{
	int	i;
	int	current_index;
	int	next_index;

	if (!stack_a || is_empty(stack_a) || size < 2)
		return (0);
	i = 0;
	while (i < size - 1)
	{
		current_index = (stack_a->head + i) % stack_a->capacity;
		next_index = (stack_a->head + i + 1) % stack_a->capacity;
		if (stack_a->arr[next_index].rank != stack_a->arr[current_index].rank
			+ 1)
			return (0);
		i++;
	}
	return (1);
}

int	is_ascending(t_stack *stack_a, int size)
{
	int	i;
	int	current_index;
	int	next_index;

	i = 0;
	if (is_empty(stack_a))
		return (-1);
	while (i < size - 1)
	{
		current_index = (stack_a->head + i) % stack_a->capacity;
		next_index = (stack_a->head + i + 1) % stack_a->capacity;
		if (stack_a->arr[current_index].value > stack_a->arr[next_index].value)
			return (0);
		i++;
	}
	return (1);
}

int	is_descending(t_stack *stack_b, int size)
{
	int	i;
	int	current_index;
	int	next_index;

	i = 0;
	if (is_empty(stack_b))
		return (-1);
	while (i < size - 1)
	{
		current_index = (stack_b->head + i) % stack_b->capacity;
		next_index = (stack_b->head + i + 1) % stack_b->capacity;
		if (stack_b->arr[current_index].value < stack_b->arr[next_index].value)
			return (0);
		i++;
	}
	return (1);
}
