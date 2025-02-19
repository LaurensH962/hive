/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:34:42 by lhaas             #+#    #+#             */
/*   Updated: 2025/02/12 18:06:17 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pivot(t_stack *stack)
{
	int	min;
	int	max;
	int	i;
	int	count;
	int	current;

	min = stack->arr[stack->head].rank;
	max = stack->arr[stack->head].rank;
	i = stack->head;
	count = 0;
	while (count < stack->size)
	{
		current = stack->arr[i].rank;
		if (current < min)
			min = current;
		if (current > max)
			max = current;
		i = (i + 1) % stack->capacity;
		count++;
	}
	return ((min + max) / 2);
}

int	qs_basecase(t_stack *stack_a, t_stack *stack_b, char what_stack)
{
	if ((what_stack == 'a' && stack_a->size <= 1) || (what_stack == 'b'
			&& stack_b->size <= 1))
		return (-1);
	if (what_stack == 'a' && is_strictly_sequential_asc(stack_a, stack_a->size))
		return (-1);
	if (what_stack == 'b' && is_strictly_sequential_desc(stack_b,
			stack_b->size))
		return (-1);
	if (stack_b->size <= 3 && what_stack == 'b' && !is_descending(stack_b,
			stack_b->size))
	{
		sort_three_des(stack_b, stack_b->size);
		return (-1);
	}
	if (stack_a->size <= 3 && what_stack == 'a' && !is_ascending(stack_a,
			stack_a->size))
	{
		sort_three_asc(stack_a, stack_a->size);
		return (-1);
	}
	return (0);
}

void	q_sort_init(t_stack *stack_a, t_stack *stack_b, char what_stack,
		int pivot)
{
	if (what_stack == 'c' && stack_a->size > 3)
	{
		pivot = find_pivot(stack_a);
		partition_init(stack_a, stack_b, pivot);
		what_stack = 'd';
	}
	if (what_stack == 'd' && stack_a->size > 3)
	{
		pivot = find_pivot(stack_b);
		partition_init_b(stack_a, stack_b, pivot);
		what_stack = 'a';
	}
}

void	quick_sort(t_stack *stack_a, t_stack *stack_b, char what_stack,
		int pivot)
{
	if (qs_basecase(stack_a, stack_b, what_stack) == -1)
		return ;
	if (what_stack == 'c' && stack_a->size > 3)
		q_sort_init(stack_a, stack_b, 'c', pivot);
	if (what_stack == 'a' && stack_a->size > 3)
	{
		pivot = find_pivot(stack_a);
		partition(stack_a, stack_b, pivot);
	}
	if (what_stack == 'b' && stack_b->size > 3)
	{
		pivot = pivot * 0.91;
		partition_b(stack_a, stack_b, pivot);
	}
	quick_sort(stack_a, stack_b, 'a', pivot);
	quick_sort(stack_a, stack_b, 'b', pivot);
	while (!is_empty(stack_b))
	{
		push(stack_a, pop(stack_b));
		ft_printf("pa\n");
	}
	return ;
}
