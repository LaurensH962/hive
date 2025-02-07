/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_asc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:08:26 by lhaas             #+#    #+#             */
/*   Updated: 2025/02/07 14:08:29 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_asc_help_2(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	sort_three_asc_help(t_stack *stack_a, int first, int second, int third)
{
	if (first > second && second > third)
		sort_three_asc_help_2(stack_a);
	else if (first > third && third > second)
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
	else if (second > third && third > first)
	{
		reverse_rotate(stack_a);
		swap(stack_a);
		ft_printf("rra\nsa\n");
	}
	else if (second > first && first > third)
	{
		reverse_rotate(stack_a);
		ft_printf("rra\n");
	}
	else if (first > second && second < third)
	{
		swap(stack_a);
		ft_printf("sa\n");
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
		if (stack_a->arr[stack_a->head].rank > stack_a->arr[(stack_a->head + 1)
				% stack_a->capacity].rank)
		{
			swap(stack_a);
			ft_printf("sa\n");
		}
		return ;
	}
	first = stack_a->arr[stack_a->head].rank;
	second = stack_a->arr[(stack_a->head + 1) % stack_a->capacity].rank;
	third = stack_a->arr[(stack_a->head + 2) % stack_a->capacity].rank;
	sort_three_asc_help(stack_a, first, second, third);
}
