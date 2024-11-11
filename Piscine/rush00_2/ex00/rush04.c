/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:29:42 by imunaev-          #+#    #+#             */
/*   Updated: 2024/08/04 10:59:32 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern void	ft_putchar(char l);

void	display_first_line(int x)
{
	char	a;
	char	b;
	char	c;
	char	new_line;

	a = 'A';
	b = 'B';
	c = 'C';
	new_line = '\n';
	ft_putchar(a);
	if (x == 2)
	{
		ft_putchar(c);
	}
	if (x > 2)
	{
		while ((x - 2) > 0)
		{
			ft_putchar(b);
			x--;
		}
		ft_putchar(c);
	}
	ft_putchar(new_line);
}

void	display_last_line(int x)
{
	char	a;
	char	b;
	char	c;
	char	new_line;

	a = 'A';
	b = 'B';
	c = 'C';
	new_line = '\n';
	ft_putchar(c);
	if (x == 2)
	{
		ft_putchar(a);
	}
	if (x > 2)
	{
		while ((x - 2) > 0)
		{
			ft_putchar(b);
			x--;
		}
		ft_putchar(a);
	}
	ft_putchar(new_line);
}

void	display_line_between(int x)
{
	char	b;
	char	space;
	char	new_line;

	b = 'B';
	space = ' ';
	new_line = '\n';
	ft_putchar(b);
	if (x == 2)
	{
		ft_putchar(b);
	}
	if (x > 2)
	{
		while ((x - 2) > 0)
		{
			ft_putchar(space);
			x--;
		}
		ft_putchar(b);
	}
	ft_putchar(new_line);
}

void	display_lines(int x, int y)
{
	display_first_line(x);
	if (y == 2)
	{
		display_last_line(x);
	}
	if (y > 2)
	{
		while ((y - 2) > 0)
		{
			display_line_between(x);
			y--;
		}
		display_last_line(x);
	}
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		display_lines(x, y);
	}
}
