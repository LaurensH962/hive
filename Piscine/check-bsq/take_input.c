/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:40:06 by atran             #+#    #+#             */
/*   Updated: 2024/08/21 18:45:34 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*str_in(void)
{
	char	*f_name;
	char	f_read[128000];

	f_name = (char *)malloc(100000000 * sizeof(char));
	f_name[0] = '\0';
	while ((read(STDIN_FILENO, f_read, 128000 - 1)) > 0)
	{
		ft_strcat(f_name, f_read);
	}
	return (f_name);
}
