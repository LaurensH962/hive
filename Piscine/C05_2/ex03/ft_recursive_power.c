/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:24:16 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/15 16:06:07 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power (nb, power - 1));
}
/*
int	main(void)
{
	int i = 5;
	int p = 10;

	printf("%d", ft_recursive_power (i,p));
	return (0);
}
*/
