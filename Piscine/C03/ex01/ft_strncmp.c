/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:56:45 by lhaas             #+#    #+#             */
/*   Updated: 2024/08/09 09:53:19 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/*
int     main(void)
{
	int	n = 7;
        int a = 1;
        char      s1[] = "hello";
        char      s2[] = "hello";
        a = ft_strncmp (s1, s2, n);
        printf("%d",a);
        return (0);
}
*/
