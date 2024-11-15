/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:31:30 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/14 09:30:36 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	x;
	int	i;

	i = 0;
	while (i < 46340)
	{
		x = i * i;
		if (x == nb)
			return (i);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	int i = 16;
	printf("%d", ft_sqrt(i));
	return (0);
}
*/
