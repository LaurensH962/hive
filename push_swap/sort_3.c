/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:04:17 by lhaas             #+#    #+#             */
/*   Updated: 2025/01/23 17:06:30 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ascending(t_stack *stack_a, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack_a->arr[(stack_a->head + i)
			% stack_a->capacity] > stack_a->arr[(stack_a->head + i + 1)
			% stack_a->capacity])
			return (0);
		i++;
	}
	return (1);
}

int	is_descending(t_stack *stack_b, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack_b->arr[(stack_b->head + i)
			% stack_b->capacity] < stack_b->arr[(stack_b->head + i + 1)
			% stack_b->capacity])
			return (0);
		i++;
	}
	return (1);
}

void	sort_two_des(t_stack *stack_b, int size)
{
	int	temp;

	if (size <= 1 || is_descending(stack_b, size))
		return ;
	if (stack_b->arr[stack_b->head] < stack_b->arr[(stack_b->head + 1)
		% stack_b->capacity])
	{
		temp = stack_b->arr[stack_b->head];
		stack_b->arr[stack_b->head] = stack_b->arr[(stack_b->head + 1)
			% stack_b->capacity];
		stack_b->arr[(stack_b->head + 1) % stack_b->capacity] = temp;
	}
	// printf("\n2 or less b: ");
	// print_stack(stack_b);
}

void	sort_two_asc(t_stack *stack_a, int size)
{
	int	temp;

	if (size <= 1 || is_ascending(stack_a, size))
		return ;
	if (stack_a->arr[stack_a->head] > stack_a->arr[(stack_a->head + 1)
		% stack_a->capacity])
	{
		temp = stack_a->arr[stack_a->head];
		stack_a->arr[stack_a->head] = stack_a->arr[(stack_a->head + 1)
			% stack_a->capacity];
		stack_a->arr[(stack_a->head + 1) % stack_a->capacity] = temp;
	}
}

void	sort_three_asc(t_stack *stack_a, int size)
{
	int	first;
	int	second;
	int	third;

	if (size <= 1)
		return ;
	if (is_ascending(stack_a, size))
		return ;
	if (size == 2)
	{
		if (stack_a->arr[stack_a->head] > stack_a->arr[(stack_a->head + 1)
			% stack_a->capacity])
		{
			swap(stack_a);
			ft_printf("sa\n");
		}
		return ;
	}
	first = stack_a->arr[stack_a->head];
	second = stack_a->arr[(stack_a->head + 1) % stack_a->capacity];
	third = stack_a->arr[(stack_a->head + 2) % stack_a->capacity];
	if (first > second && second > third)
	{
		swap(stack_a);
		ft_printf("sa\n");
		reverse_rotate(stack_a);
		ft_printf("rra\n");
	}
	else if (first > second && first > third)
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
	else if (second > first && second > third && first < third)
	{
		reverse_rotate(stack_a);
		ft_printf("rra\n");
		swap(stack_a);
		ft_printf("sa\n");
	}
	else if (second > first && second > third && first > third)
	{
		reverse_rotate(stack_a);
		ft_printf("rra\n");
	}
	else if (first > second && first < third)
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
}

void	sort_three_des(t_stack *stack_b, int size)
{
	int	first;
	int	second;
	int	third;

	if (size <= 1)
		return;
	if (is_descending(stack_b, size))
		return;

	if (size == 2) // Special case for two elements
	{
		if (stack_b->arr[stack_b->head] < stack_b->arr[(stack_b->head + 1) % stack_b->capacity])
		{
			swap(stack_b);
			ft_printf("sb\n");
		}
		return;
	}
	first = stack_b->arr[stack_b->head];
	second = stack_b->arr[(stack_b->head + 1) % stack_b->capacity];
	third = stack_b->arr[(stack_b->head + 2) % stack_b->capacity];
	if (first < second && second < third) // 1 2 3 -> 3 2 1
	{
		swap(stack_b);
		ft_printf("sb\n");
		reverse_rotate(stack_b);
		ft_printf("rrb\n");
	}
	else if (first < third && third < second) // 1 3 2 -> 3 2 1
	{
		rotate(stack_b);
		ft_printf("rb\n");
	}
	else if (second < third && third < first) // 2 3 1 -> 3 2 1
	{
		rotate(stack_b);
		ft_printf("rb\n");
	}
	else if (second < first && first < third) // 2 1 3 -> 3 2 1
	{
		reverse_rotate(stack_b);
		ft_printf("rrb\n");
	}
	else if (third < first && first < second) // 3 1 2 -> 3 2 1
	{
		swap(stack_b);
		ft_printf("sb\n");
	}
}

