/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:35:19 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/22 16:16:28 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	find_length(char *str)
{
	int	p;

	p = 0;
	while (str[p])
		p++;
	return (p);
}

char	*str_copy(char **strs, char *str, int size, char *sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			str[k++] = strs[i][j++];
		}
		if (i < size -1)
		{	
			j = 0;
			while (sep[j])
				str[k++] = sep[j++];
		}
		i++;
	}
	str[k] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	len = 0;
	if (size == 0)
	{
		result = malloc(1);
		result[0] = '\0';
		return (result);
	}
	while (i < size)
	{
		len = len + find_length(strs[i]);
		i++;
	}
	len = len + find_length(sep) * (size - 1);
	result = (char *)malloc((len + 1) * sizeof(char));
	result = str_copy(strs, result, size, sep);
	return (result);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	char sep[] = "___________";
	printf("%s", ft_strjoin (argc, argv, sep));
	return (0);
}*/
