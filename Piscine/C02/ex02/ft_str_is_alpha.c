/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:09:27 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/06 14:34:34 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 65) || (str[i] > 90 && str[i] < 97) || (str[i] > 122))
		{
			return (0);
		}	
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	char	letters[] = "abcde1fsd";
	ft_str_is_alpha(letters);
	return (0);
}
*/
