/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:41:17 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/11 14:44:15 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(char **ar, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(ar[i]);
		i++;
	}
	free(ar);
	return (NULL);
}

size_t	count_len(const char *s, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (len);
		len++;
		i++;
	}
	return (len);
}

size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		while (*s && *s == c)
			s++;
	}
	return (count);
}

char	**ft_helpsplit(char const *s, char c, char **ar, size_t count)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (i < count && *s != '\0')
	{
		if (*s && *s != c)
		{
			ar[i] = (char *)malloc((count_len(s, c) + 1) * (sizeof(char)));
			if (!ar[i])
				return (ft_free(ar, i));
			ft_strlcpy(ar[i], s, count_len(s, c) + 1);
			i++;
			while (*s && *s != c)
				s++;
		}
		while (*s && *s == c)
		{
			s = ft_strchr(s, c);
			s++;
		}
	}
	ar[i] = NULL;
	return (ar);
}

char	**ft_split(char const *s, char c)
{
	char	**ar;
	size_t	i;
	size_t	count;

	i = 0;
	if (!s)
		return (NULL);
	count = count_words(s, c);
	ar = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ar)
		return (NULL);
	ar = ft_helpsplit(s, c, ar, count);
	return (ar);
}
/*
#include <stdio.h>
int	main(void)
{
	char	sp;
	char	**arr;
	int		i;

	sp = ' ';
	i = 0;
	arr = ft_split("lorem ipsum dolceuismod non, mi.", 'z');
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
} */
