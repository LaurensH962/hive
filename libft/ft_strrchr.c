/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:56:37 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/11 14:40:08 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;
	char			*res;

	i = 0;
	cc = (char)c;
	res = NULL;
	while (s[i])
	{
		if (s[i] == cc)
			res = (char *)&s[i];
		i++;
	}
	if (s[i] == cc)
		res = (char *)&s[i];
	return (res);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	str[] = "find.theor you'rebad";
	const char	ch = '.';
	char		*ret;

	ret = ft_strrchr(str, ch);
	printf("%s\n", ret);
	return (0);
}
*/
