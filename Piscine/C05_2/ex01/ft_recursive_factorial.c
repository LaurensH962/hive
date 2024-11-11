/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:30:22 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/12 15:06:22 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	else
		return (nb * ft_recursive_factorial (nb - 1));
}
/*
int	main(void)
{
	int i = 10;
	printf("%d", ft_recursive_factorial (i));
	return (0);
}*/
