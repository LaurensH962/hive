/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:37:41 by lhaas             #+#    #+#             */
/*   Updated: 2025/02/13 10:07:53 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_indices(t_stack *stack, int *indices)
{
	int	i;
	int	j;
	int	temp;

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
}

void	rank_stack(t_stack *stack)
{
	int	*indices;
	int	i;

	indices = malloc(stack->size * sizeof(int));
	if (!indices)
		return ;
	i = 0;
	while (i < stack->size)
	{
		indices[i] = i;
		i++;
	}
	sort_indices(stack, indices);
	i = 0;
	while (i < stack->size)
	{
		stack->arr[indices[i]].rank = i + 1;
		i++;
	}
	free(indices);
}

void	fill_stack(t_stack *stack_a, char *argv[], int argc, int i)
{
	int	num;

	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		first_push(stack_a, num);
		i++;
	}
	rank_stack(stack_a);
}

int	get_argv2_height(char *argv2[])
{
	int	i;

	i = 0;
	while (argv2[i])
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		range_size;
	int		i;

	i = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = get_argv2_height(argv);
		i = 0;
	}
	if (check_input(argc, argv, i))
	{
		free_arr(argv, i);
		write(2, "Error\n", 6);
		return (1);
	}
	init_stack(&stack_a, argc - i);
	init_stack(&stack_b, argc - i);
	fill_stack(&stack_a, argv, argc, i);
	range_size = stack_a.size;
	quick_sort(&stack_a, &stack_b, 'c', range_size);
	free_all(stack_a, stack_b, argv, i);
	return (0);
}
