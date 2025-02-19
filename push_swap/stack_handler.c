/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:10:10 by lhaas             #+#    #+#             */
/*   Updated: 2025/02/11 16:08:20 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_push(t_stack *stack, int num)
{
	if (is_full(stack))
		return ;
	stack->arr[stack->tail].value = num;
	stack->tail = (stack->tail + 1) % stack->capacity;
	stack->size++;
}

void	init_stack(t_stack *stack, int capacity)
{
	stack->arr = (t_element *)malloc(sizeof(t_element) * capacity);
	if (!stack->arr)
		return ;
	stack->arr->value = 0;
	stack->arr->rank = 0;
	stack->size = 0;
	stack->capacity = capacity;
	stack->head = 0;
	stack->tail = 0;
}

int	is_full(t_stack *stack)
{
	return (stack->size == stack->capacity);
}

int	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}
