/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:37:41 by lhaas             #+#    #+#             */
/*   Updated: 2025/01/23 16:48:29 by lhaas            ###   ########.fr       */
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

void	init_stack(t_stack *stack, int capacity)
{
	stack->arr = (int *)malloc(sizeof(int) * capacity);
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

void	push(t_stack *stack, int value)
{
	if (is_full(stack))
	{
		// printf("Error: Stack is full. Cannot push %d.\n", value);
		return ;
	}
	stack->head = (stack->head + stack->capacity - 1) % stack->capacity;
	stack->arr[stack->head] = value;
	stack->size++;
	// printf("pp\n");
}

void	first_push(t_stack *stack, int value)
{
	if (is_full(stack))
	{
		return ;
	}
	stack->arr[stack->tail] = value;
	stack->tail = (stack->tail + 1) % stack->capacity;
	stack->size++;
}

int	pop(t_stack *stack)
{
	int	value;

	if (is_empty(stack))
		return (-1);
	value = stack->arr[stack->head];
	stack->head = (stack->head + 1) % stack->capacity;
	stack->size--;
	return (value);
}

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->arr[stack->head];
	stack->arr[stack->head] = stack->arr[(stack->head + 1) % stack->capacity];
	stack->arr[(stack->head + 1) % stack->capacity] = temp;
	// printf("sw\n");
}

void	rotate(t_stack *stack)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->arr[stack->head];
	stack->head = (stack->head + 1) % stack->capacity;
	stack->arr[stack->tail] = temp;
	stack->tail = (stack->tail + 1) % stack->capacity;
	// printf("rr\n");
}

void	reverse_rotate(t_stack *stack)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->arr[(stack->tail + stack->capacity - 1) % stack->capacity];
	stack->tail = (stack->tail + stack->capacity - 1) % stack->capacity;
	stack->head = (stack->head + stack->capacity - 1) % stack->capacity;
	stack->arr[stack->head] = temp;
}

int	find_pivot(t_stack *stack)
{
	int	first;
	int	middle;
	int	last;

	if (stack->size < 3)
	{
		// printf("Warning: Stack size is less than 3. Using the first element as the pivot.\n");
		return (stack->arr[stack->head]);
	}
	first = stack->arr[stack->head];
	middle = stack->arr[(stack->head + stack->size / 2) % stack->capacity];
	last = stack->arr[(stack->head + stack->size - 1) % stack->capacity];
	if ((first > middle) != (first > last))
		return (first);
	else if ((middle > first) != (middle > last))
		return (middle);
	else
		return (last);
}

void	partition(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int	original_size;
	int	rotations;

	original_size = stack_a->size;
	rotations = 0;
	for (int i = 0; i < original_size; i++)
	{
		if (is_ascending(stack_a, stack_a->size))
			return;
		if (stack_a->arr[stack_a->head] < pivot)
		{
			push(stack_b, pop(stack_a));
			ft_printf("pb\n");
		}
		/* 		if (stack_b->arr[stack_b->head] < stack_b->arr[(stack_b->head
						+ 1) % stack_b->capacity])
					swap(stack_b); */
		else
		{
			rotate(stack_a);
			ft_printf("ra\n");
			rotations++;
		}
		if (rotations == original_size)
			break ;
	}
	/* printf("\nPartition A complete. \nStack A: ");
	print_stack(stack_a);
	printf("Stack B: ");
	print_stack(stack_b); */
}

void	partition_b(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int	original_size;
	int	rotations;

	original_size = stack_b->size;
	rotations = 0;
	for (int i = 0; i < original_size; i++)
	{
		if (stack_b->arr[stack_b->head] < stack_b->arr[(stack_b->head + 1)
			% stack_b->capacity])
		{
			swap(stack_b);
			ft_printf("sb\n");
		}
		if (is_descending(stack_b, stack_b->size))
			return;
		if (stack_b->arr[stack_b->head] > pivot)
		{
			push(stack_a, pop(stack_b));
			ft_printf("pa\n");
		}
		else
		{
			rotate(stack_b);
			ft_printf("rb\n");
			rotations++;
		}
		if (rotations == original_size)
			break ;
	}
	/* printf("\nPartition B complete. \nStack A: ");
	print_stack(stack_a);
	printf("Stack B: ");
	print_stack(stack_b); */
}

void	quick_sort(t_stack *stack_a, t_stack *stack_b, char what_stack)
{
    int	pivot;

    if (stack_b->size <= 3 && what_stack == 'b' && !is_descending(stack_b, stack_b->size))
    {
        sort_three_des(stack_b, stack_b->size);
        return;
    }
    if (stack_b->size <= 3 && what_stack == 'a' && !is_descending(stack_b, stack_b->size))
    {
        sort_three_des(stack_b, stack_b->size);
    }
	 if (stack_a->size <= 3 && what_stack == 'a' && !is_ascending(stack_a, stack_a->size))
    {
        sort_three_asc(stack_a, stack_a->size);
        return;
    }
    if (stack_a->size <= 3 && what_stack == 'b' && !is_ascending(stack_a, stack_a->size))
    {
        sort_three_asc(stack_a, stack_a->size);
    }
   

    // If both stacks are sorted, move all elements from stack_b to stack_a
    if (is_ascending(stack_a, stack_a->size) && is_descending(stack_b, stack_b->size) && stack_a->head > stack_b->head)
    {
        while (!is_empty(stack_b))
        {
            push(stack_a, pop(stack_b));
            ft_printf("pa\n");
        }
        return;
    }

    // If the current stack is already sorted, return
    if (what_stack == 'a' && is_ascending(stack_a, stack_a->size))
        return;
    if (what_stack == 'b' && is_descending(stack_b, stack_b->size))
        return;

    // Partition the current stack based on the pivot
    if (what_stack == 'a' && stack_a->size > 3)
    {
        pivot = find_pivot(stack_a);
        partition(stack_a, stack_b, pivot);
    }
    if (what_stack == 'b' && stack_b->size > 3)
    {
        pivot = find_pivot(stack_b);
        partition_b(stack_a, stack_b, pivot);
    }

    // Recursively sort the partitions
	quick_sort(stack_a, stack_b, 'a');
    quick_sort(stack_a, stack_b, 'b');


    // Move all elements from stack_b to stack_a after sorting
    while (!is_empty(stack_b))
    {
        push(stack_a, pop(stack_b));
        ft_printf("pa\n");
    }
}
void	print_stack(t_stack *stack)
{
	int i, count;
	i = stack->head;
	count = 0;
	// printf("Stack contents: ");
	while (count < stack->size)
	{
		printf("%d ", stack->arr[i]);
		i = (i + 1) % stack->capacity;
		count++;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	int	i;
	int	num;

	t_stack stack_a, stack_b;
	init_stack(&stack_a, argc - 1);
	init_stack(&stack_b, argc - 1);
	for (i = 1; i < argc; i++)
	{
		num = ft_atoi(argv[i]);
		first_push(&stack_a, num);
	}
	printf("Initial Stack A: ");
	print_stack(&stack_a);
	quick_sort(&stack_a, &stack_b, 'a');
	printf("\nSorted Stack A: ");
	print_stack(&stack_a);
	printf("Sorted Stack B: ");
	print_stack(&stack_b);
	return (0);
}
