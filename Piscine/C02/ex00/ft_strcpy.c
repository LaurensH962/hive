/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaa@student.hive.fi>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:01:55 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/07 10:34:24 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	c;

	c = 0;
	while (src[c] != '\0')
	{
		dest[c] = src[c];
		c++;
	}
	dest[c] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	b[] = "copy me";
	char	a[30];

	ft_strcpy(a, b);
	printf("%s\n", a);
	return (0);
}*/
