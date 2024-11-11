/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:43:13 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/05 09:42:22 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char i, char j, char k)
{
	write (1, &i, 1);
	write (1, &j, 1);
	write (1, &k, 1);
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	while (i <= '7')
	{
		j = i + 1;
		while (j <= '8')
		{
			k = j + 1;
			while (k <= '9')
			{
				ft_putchar (i, j, k);
				if (i != '7')
				{
					write(1, ", ", 2);
				}
				k++;
			}
			j++;
		}
		i++;
	}
}

/*
int	main(void)
{
	ft_print_comb ();
	return (0);
}
*/
