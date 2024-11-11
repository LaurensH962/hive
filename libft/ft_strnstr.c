/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:07:46 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/11 11:56:58 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_l;
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (0);
	little_l = ft_strlen(little);
	i = 0;
	if (little_l == 0)
		return ((char *)big);
	while (*big != '\0' && i < (len - little_l))
	{
		if (ft_strncmp(big, little, little_l) == 0)
			return ((char *)big);
		big++;
		i++;
	}
	if (ft_strncmp(big, little, little_l) == 0)
		return ((char *)big);
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	char	*res;

	s2 = "asdasd";
	s1 = (void *)NULL;
	res = ft_strnstr(s1, s2, 8);
	printf("%s\n", (res) ? res : "NULL");
	return (0);
}
 */
