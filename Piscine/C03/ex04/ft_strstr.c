/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:21:43 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/09 09:58:01 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	compare(char *str, char *to_find)
{
	while (*str && *to_find)
	{
		if (*str != *to_find)
		{
			return (0);
		}
		str++;
		to_find++;
	}
	return (*to_find == '\0');
}

char	*ft_strstr(char *str, char *to_find)
{
	while (*str != '\0')
	{
		if ((*str == *to_find) && compare (str, to_find))
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*str = "this is the test: Here I go!";
	char	*to_find = "Here";
	printf("%s", ft_strstr(str, to_find));
	return (0);
}
*/
