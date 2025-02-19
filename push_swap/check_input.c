/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:18:45 by lhaas             #+#    #+#             */
/*   Updated: 2025/02/12 17:47:27 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(const char *str)
{
	if (*str == '-' || *str == '+')
	{
		str++;
		if (!ft_isdigit(*str))
			return (0);
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	has_duplicates(int argc, char *argv[], int i)
{
	int	j;

	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_int_range(const char *str)
{
	long long	value;

	value = ft_atoi(str);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	return (1);
}

int	check_input(int argc, char *argv[], int i)
{
	int	j;

	j = i;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (1);
		if (!check_int_range(argv[i]))
			return (1);
		i++;
	}
	if (has_duplicates(argc, argv, j))
		return (1);
	return (0);
}
