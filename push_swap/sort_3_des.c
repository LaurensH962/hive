/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_des.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:04:17 by lhaas             #+#    #+#             */
/*   Updated: 2025/02/07 14:09:23 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_des_help_2(t_stack *stack_b)
{
	swap(stack_b);
	reverse_rotate(stack_b);
	ft_printf("sb\nrrb\n");
}

void	sort_three_des_help(t_stack *stack_b, int first, int second, int third)
{
	if (first < second && second < third)
		sort_three_des_help_2(stack_b);
	else if (first < third && third < second)
	{
		rotate(stack_b);
		ft_printf("rb\n");
	}
	else if (second < third && third < first)
	{
		reverse_rotate(stack_b);
		ft_printf("rrb\nsb\n");
		swap(stack_b);
	}
	else if (second < first && first < third)
	{
		reverse_rotate(stack_b);
		ft_printf("rrb\n");
	}
	else if (third < first && first < second)
	{
		swap(stack_b);
		ft_printf("sb\n");
	}
}

void	sort_three_des(t_stack *stack_b, int size)
{
	int	first;
	int	second;
	int	third;

	if (is_descending(stack_b, size))
		return ;
	if (size == 2)
	{
		if (stack_b->arr[stack_b->head].rank < stack_b->arr[(stack_b->head + 1)
				% stack_b->capacity].rank)
		{
			swap(stack_b);
			ft_printf("sb\n");
		}
		return ;
	}
	first = stack_b->arr[stack_b->head].rank;
	second = stack_b->arr[(stack_b->head + 1) % stack_b->capacity].rank;
	third = stack_b->arr[(stack_b->head + 2) % stack_b->capacity].rank;
	sort_three_des_help(stack_b, first, second, third);
}
