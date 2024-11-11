/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:42:56 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/08 13:42:05 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check if first letter is small. check if letter before is no letter.
char	*check_characters(char *str, int i)
{
	if ((i == 0) && (str[i] > 96 && str[i] < 123))
		str[i] = str[i] - 32;
	if ((i > 0) && (str[i] > 64 && str[i] < 91))
		str[i] = str[i] + 32;
	if ((str[i] > 96 && str[i] < 123))
	{
		if (!(str[i - 1] > 64 && str[i - 1] < 91))
		{
			if (!(str[i - 1] > 96 && str[i - 1] < 123))
			{
				if (!(str[i - 1] > 47 && str[i - 1] < 58))
					str[i] = str[i] - 32;
			}
		}
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		check_characters (str, i);
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	letters[] = "+th+is is a t:st 0f so__m3t/hing";

	ft_strcapitalize (letters);
	printf("%s",letters);
	return (0);
}
*/
