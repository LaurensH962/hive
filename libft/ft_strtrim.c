/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:06:10 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/11 11:15:14 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_char(int c, char const *set)
{
	size_t	i;

	i = 0;
	while (i < (ft_strlen(set)))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	lefttrim(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (is_char(*s1, set))
	{
		i++;
		s1++;
	}
	return (i);
}

int	righttrim(char const *s1, char const *set)
{
	char	*b;
	int		i;

	i = 0;
	b = (char *)s1 + ft_strlen(s1);
	while (is_char(*--b, set))
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		left;
	int		right;

	if (!s1)
		return (NULL);
	left = lefttrim(s1, set);
	right = lefttrim(s1, set) + righttrim(s1, set);
	if (!s1 || !set)
		return (NULL);
	res = ft_substr(s1, left, ft_strlen(s1) - right);
	return (res);
}
/* #include <stdio.h>
int	main(void)
{
	char	s1[] = "   \t  \n\n \t\t  \n\n\nHello \t
	 Please\n ,Trim me !,\n   \n \n \t\t\n  ";
	char	set[] = "  \n\t,";

	printf("%s", ft_strtrim(s1, set));
	return (0);
} */
