/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:30:43 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/06 13:55:05 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	i;

	i = *a / *b;
	*b = *a % *b;
	*a = i;
}
/*
int	main(void)
{
	int	a;
	int	b;

	a = 42;
	b = 23;
	ft_ultimate_div_mod(&a, &b);
	return (0);
}
*/
