/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:34:14 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/11 11:11:14 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s + start)))
		len = ft_strlen(s + start);
	p = ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	return (p);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s[] = "copy THIS and not more";
	int		start;
	int		len;

	start = 5;
	len = 4;
	printf ("%s\n", ft_substr(s,start,len));
	return (0);
}
*/
/* int	main(void)
{
	char const src[19] = "0123456789";
	char *result1, *result3, *result5, *result7, *result8;
	char *result2, *result4, *result6;

	result1 = ft_substr(src, 3, 3);
	printf("The substring is: %s\n", result1);
	result2 = ft_substr(src, 3, 0);
	printf("The substring is: %s\n", result2);
	result3 = ft_substr(src, 3, 1);
	printf("The substring is: %s\n", result3);
	result4 = ft_substr(src, 3, 20);
	printf("The substring is: %s\n", result4);
	result5 = ft_substr(src, 0, 3);
	printf("The substring is: %s\n", result5);
	result6 = ft_substr(src, 20, 3);
	printf("The substring is: %s\n", result6);
	result7 = ft_substr(NULL, 3, 3);
	printf("The substring is: %s\n", result7);
	result8 = ft_substr(NULL, 0, 0);
	printf("The substring is: %s\n", result8);
	free(result1);
	free(result2);
	free(result3);
	free(result4);
	free(result5);
	free(result6);
	free(result7);
	free(result8);
	return (0);
} */
