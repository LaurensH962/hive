/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:37:41 by lhaas             #+#    #+#             */
/*   Updated: 2025/02/07 15:43:48 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

int	main(int argc, char *argv[])
{
	char	**split_numbers;
	int		j;
	int		i;
	int		num;
	int		size;
	int		*arr;
	int		median;

	size = 0;
	if (argc < 2)
		return (1);
	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			split_numbers = ft_split(argv[i], ' ');
			if (!split_numbers)
			{
				free(arr);
				return (1);
			}
			j = 0;
			while (split_numbers[j] != NULL)
			{
				num = ft_atoi(split_numbers[j]);
				arr[size++] = num;
				free(split_numbers[j]);
				j++;
			}
			free(split_numbers);
		}
		else
		{
			num = ft_atoi(argv[i]);
			arr[size++] = num;
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	ft_printf("size is: %d\n", size);
	median = find_median(arr, size);
	ft_printf("The median of the array is: %d\n", median);
	free(arr);
	return (0);
}
*/

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

int	find_next_index_a(t_stack *stack, int pivot)
{
	int	i;
	int	size;
	int	idx;

	size = stack->size;
	i = 0;
	while (i < size)
	{
		idx = (stack->head + i) % stack->capacity;
		if (stack->arr[idx].rank < pivot)
			return (i);
		i++;
	}
	return (-1);
}

int	has_smaller_than_pivot(t_stack *stack, int pivot)
{
	int	i;
	int	count;

	i = stack->head;
	count = 0;
	while (count < stack->size)
	{
		if (stack->arr[i].rank < pivot)
			return (1);
		i = (i + 1) % stack->capacity;
		count++;
	}
	return (0);
}

void	partition(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int	original_size;
	int	moves;
	int	next_index;
	int	i;

	original_size = stack_a->size;
	moves = 0;
	i = 0;
	while (i < original_size)
	{
		if (is_strictly_sequential_asc(stack_a, stack_a->size))
			return ;
		if (has_smaller_than_pivot(stack_a, pivot))
		{
			if (stack_b->size > 3
				&& stack_b->arr[stack_b->head].rank < stack_b->arr[(stack_b->head
						+ 1) % stack_b->capacity].rank
				&& stack_b->arr[stack_b->head].rank <= pivot
				&& stack_a->arr[stack_a->head].rank > stack_a->arr[(stack_a->head
						+ 1) % stack_a->capacity].rank
				&& stack_a->arr[stack_a->head].rank <= pivot)
			{
				swap(stack_b);
				swap(stack_a);
				ft_printf("ss\n");
			}
			else if (stack_a->size > 3
				&& stack_a->arr[stack_a->head].rank > stack_a->arr[(stack_a->head
						+ 1) % stack_a->capacity].rank
				&& stack_a->arr[stack_a->head].rank <= pivot)
			{
				swap(stack_a);
				ft_printf("sa\n");
			}
			if (stack_a->arr[stack_a->head].rank <= pivot)
			{
				push(stack_b, pop(stack_a));
				moves++;
				ft_printf("pb\n");
			}
			else
			{
				next_index = find_next_index_a(stack_a, pivot);
				if (next_index != -1)
				{
					if (next_index <= stack_a->size / 2)
					{
						rotate(stack_a);
						ft_printf("ra\n");
					}
					else
					{
						reverse_rotate(stack_a);
						ft_printf("rra\n");
					}
					moves++;
				}
			}
		}
		if (moves == original_size)
			break ;
		i++;
	}
}

int	find_next_index_b(t_stack *stack, int pivot)
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

int	has_bigger_than_pivot(t_stack *stack, int pivot)
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

void	partition_b(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int	original_size;
	int	moves;
	int	rotated;
	int	next_index;
	int	i;

	original_size = stack_b->size;
	moves = 0;
	rotated = 0;
	i = 0;
	while (i < original_size)
	{
		if (is_strictly_sequential_desc(stack_b, stack_b->size))
			return ;
		if (has_bigger_than_pivot(stack_b, pivot))
		{
			if (stack_b->size > 3
				&& stack_b->arr[stack_b->head].rank < stack_b->arr[(stack_b->head
						+ 1) % stack_b->capacity].rank
				&& stack_b->arr[stack_b->head].rank >= pivot
				&& stack_a->size > 3
				&& stack_a->arr[stack_a->head].rank > stack_a->arr[(stack_a->head
						+ 1) % stack_a->capacity].rank
				&& stack_a->arr[stack_a->head].rank <= pivot)
			{
				swap(stack_b);
				swap(stack_a);
				ft_printf("ss\n");
			}
			else if (stack_b->size > 3
				&& stack_b->arr[stack_b->head].rank < stack_b->arr[(stack_b->head
						+ 1) % stack_b->capacity].rank
				&& stack_b->arr[stack_b->head].rank >= pivot)
			{
				swap(stack_b);
				ft_printf("sb\n");
			}
			if (stack_b->arr[stack_b->head].rank >= pivot)
			{
				push(stack_a, pop(stack_b));
				moves++;
				ft_printf("pa\n");
			}
			else
			{
				next_index = find_next_index_b(stack_b, pivot);
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
					moves++;
				}
			}
		}
		if (moves == original_size)
			break ;
		i++;
	}
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

void	quick_sort(t_stack *stack_a, t_stack *stack_b, char what_stack,
		int pivot)
{
	if (qs_basecase(stack_a, stack_b, what_stack) == -1)
		return ;
	if (what_stack == 'a' && stack_a->size > 3)
	{
		pivot = find_pivot(stack_a);
		partition(stack_a, stack_b, pivot);
	}
	if (what_stack == 'b' && stack_b->size > 3)
	{
		pivot = pivot * 0.9;
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

void	rank_stack(t_stack *stack)
{
	int	*indices;
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	indices = malloc(stack->size * sizeof(int));
	if (!indices)
		return ;
	while (i < stack->size)
	{
		indices[i] = i;
		i++;
	}
	i = 0;
	while (i < stack->size - 1)
	{
		j = 0;
		while (j < stack->size - i - 1)
		{
			if (stack->arr[indices[j]].value > stack->arr[indices[j + 1]].value)
			{
				temp = indices[j];
				indices[j] = indices[j + 1];
				indices[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < stack->size)
	{
		stack->arr[indices[i]].rank = i + 1;
		i++;
	}
	free(indices);
}

void	fill_stack(t_stack *stack_a, char *argv[], int argc)
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		first_push(stack_a, num);
		i++;
	}
	rank_stack(stack_a);
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	init_stack(&stack_a, argc - 1);
	init_stack(&stack_b, argc - 1);
	fill_stack(&stack_a, argv, argc);
	quick_sort(&stack_a, &stack_b, 'a', 0);
	free(stack_a.arr);
	free(stack_b.arr);
	return (0);
}
