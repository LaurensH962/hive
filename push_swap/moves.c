/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:17:20 by lhaas             #+#    #+#             */
/*   Updated: 2025/02/07 14:18:02 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, t_element elem)
{
	if (is_full(stack))
		return ;
	stack->head = (stack->head + stack->capacity - 1) % stack->capacity;
	stack->arr[stack->head] = elem;
	stack->size++;
}

t_element	pop(t_stack *stack)
{
	t_element	elem;

	if (is_empty(stack))
		return ((t_element){-1, -1});
	elem = stack->arr[stack->head];
	stack->head = (stack->head + 1) % stack->capacity;
	stack->size--;
	return (elem);
}

void	swap(t_stack *stack)
{
	t_element	temp;

	if (stack->size < 2)
		return ;
	temp = stack->arr[stack->head];
	stack->arr[stack->head] = stack->arr[(stack->head + 1) % stack->capacity];
	stack->arr[(stack->head + 1) % stack->capacity] = temp;
}

void	rotate(t_stack *stack)
{
	t_element	temp;

	if (stack->size < 2)
		return ;
	temp = stack->arr[stack->head];
	stack->head = (stack->head + 1) % stack->capacity;
	stack->arr[stack->tail] = temp;
	stack->tail = (stack->tail + 1) % stack->capacity;
}

void	reverse_rotate(t_stack *stack)
{
	t_element	temp;

	if (stack->size < 2)
		return ;
	temp = stack->arr[(stack->tail + stack->capacity - 1) % stack->capacity];
	stack->tail = (stack->tail + stack->capacity - 1) % stack->capacity;
	stack->head = (stack->head + stack->capacity - 1) % stack->capacity;
	stack->arr[stack->head] = temp;
}
