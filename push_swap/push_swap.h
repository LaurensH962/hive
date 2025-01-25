/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:01:37 by lhaas             #+#    #+#             */
/*   Updated: 2025/01/23 15:24:23 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	capacity;
	int	head;
	int	tail;
}		t_stack;

int		is_ascending(t_stack *stack_a, int size);
int		is_descending(t_stack *stack_b, int size);
void	sort_two_des(t_stack *stack_b, int size);
void	sort_two_asc(t_stack *stack_a, int size);
void	sort_three_asc(t_stack *stack_a, int size);
void	sort_three_des(t_stack *stack_b, int size);
void	print_stack(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	swap(t_stack *stack);
int		pop(t_stack *stack);
void	push(t_stack *stack, int value);
int		is_empty(t_stack *stack);
int		is_full(t_stack *stack);

#endif
