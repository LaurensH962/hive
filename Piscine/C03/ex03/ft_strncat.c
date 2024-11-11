/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:14:10 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/12 09:19:34 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	len;
	unsigned int	p;

	len = 0;
	p = 0;
	while (dest[len] != '\0')
	{
		len++;
	}
	while (p < nb && src[p] != '\0')
	{
		dest[len + p] = src[p];
		p++;
	}
	dest[len + p] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	dest[] = "hi you";
	char	src [] = "there hehe";
	int	nb = 5;

	printf("%s", ft_strncat (dest, src, nb));
	return (0);
}
*/
