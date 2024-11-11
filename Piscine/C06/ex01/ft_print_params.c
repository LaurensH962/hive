/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:06:28 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/21 09:25:49 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	p;

	p = 1;
	while (p < argc)
	{
		i = 0;
		while (argv[p][i])
		{
			write (1, &argv[p][i], 1);
			i++;
		}
		write (1, "\n", 1);
		p++;
	}
	return (0);
}
