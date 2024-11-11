/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:14:41 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/09 09:55:07 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	len;
	int	p;

	len = 0;
	p = 0;
	while (dest[len] != '\0')
	{
		len++;
	}
	while (src[p] != '\0')
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
	char	dest[] = "hello";
	char	src[] = " world";

	printf("%s", ft_strcat (dest, src));
	return (0);
}
*/
