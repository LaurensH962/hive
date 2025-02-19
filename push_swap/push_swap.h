/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:01:37 by lhaas             #+#    #+#             */
/*   Updated: 2025/02/12 18:13:38 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_element
{
	int			value;
	int			rank;
}				t_element;

typedef struct s_stack
{
	t_element	*arr;
	int			size;
	int			capacity;
	int			head;
	int			tail;
}				t_stack;

int				is_strictly_sequential_asc(t_stack *stack_a, int size);
int				is_strictly_sequential_desc(t_stack *stack_b, int size);
int				is_ascending(t_stack *stack_a, int size);
int				is_descending(t_stack *stack_b, int size);
void			sort_three_asc(t_stack *stack_a, int size);
void			sort_three_des(t_stack *stack_b, int size);
void			rotate(t_stack *stack);
void			reverse_rotate(t_stack *stack);
void			swap(t_stack *stack);
t_element		pop(t_stack *stack);
void			push(t_stack *stack, t_element elem);
int				is_empty(t_stack *stack);
int				is_full(t_stack *stack);
void			first_push(t_stack *stack, int num);
void			init_stack(t_stack *stack, int capacity);
void			partition(t_stack *stack_a, t_stack *stack_b, int pivot);
int				has_smaller_than_pivot(t_stack *stack, int pivot);
int				find_next_index_a(t_stack *stack, int pivot);
int				find_next_index_b(t_stack *stack, int pivot);
int				has_bigger_than_pivot(t_stack *stack, int pivot);
void			partition_b(t_stack *stack_a, t_stack *stack_b, int pivot);
void			quick_sort(t_stack *stack_a, t_stack *stack_b, char what_stack,
					int pivot);
int				is_number(const char *str);
int				has_duplicates(int argc, char *argv[], int i);
int				check_input(int argc, char *argv[], int i);
void			partition_init(t_stack *stack_a, t_stack *stack_b, int pivot);
void			partition_init_b(t_stack *stack_a, t_stack *stack_b, int pivot);
void			free_all(t_stack stack_a, t_stack stack_b, char *argv[], int i);
void			free_arr(char *argv[], int i);

#endif
