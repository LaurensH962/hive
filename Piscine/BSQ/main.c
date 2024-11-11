/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:57:21 by atran             #+#    #+#             */
/*   Updated: 2024/08/21 18:39:48 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int				valid_map(char *str);
char			*str_in(void);
int				count_words(char *f_name);
char			**print_sqr(char **grid, struct square max_sqr,
					struct elements els);
struct square	find_square(char **grid, t_elems els, struct square sqr);
char			**solve(char **grid, struct elements els);
char			*read_file(char *file_name);
char			find_char(char *str, int a);
int				ft_count_height(char *str);
int				ft_count_width(char *str);
void			free_grid(char **grid, struct elements els);
char			**create_grid(struct elements els);
char			**fill_grid(char **grid, char *str, struct elements els);
void			print_grid(char **grid, struct elements els);

void	solve_program(char *file_name, int map)
{
	char	*str;
	char	**grid;
	t_elems	els;

	str = read_file(file_name);
	if (valid_map(str) != 0)
		write(1, "map error\n", 10);
	if (valid_map(str) == 0 && map != -1)
	{
		els.col = ft_count_width(str);
		els.row = ft_count_height(str);
		els.fill = find_char(str, 1);
		els.obs = find_char(str, 2);
		els.empt = find_char(str, 3);
		grid = fill_grid(create_grid(els), str, els);
		grid = solve(grid, els);
		print_grid(grid, els);
		free_grid(grid, els);
	}
	close(map);
	free(str);
}

void	solve_stdin(void)
{
	int		j;
	char	*str;
	char	**grid;
	t_elems	els;

	j = 0;
	str = str_in();
	if (valid_map(str) != 0)
		write(1, "map error\n", 10);
	if (valid_map(str) == 0)
	{
		els.col = ft_count_width(str);
		els.row = ft_count_height(str);
		els.fill = find_char(str, 1);
		els.obs = find_char(str, 2);
		els.empt = find_char(str, 3);
		grid = fill_grid(create_grid(els), str, els);
		grid = solve(grid, els);
		print_grid(grid, els);
		free_grid(grid, els);
	}
	free(str);
}

int	main(int argc, char **argv)
{
	int		map;
	int		i;

	i = 1;
	if (argc == 1)
		solve_stdin();
	while (argc > 1 && i < argc)
	{
		map = open(argv[i], O_RDONLY);
		if (map == -1)
			write(1, "map error\n", 10);
		else
			solve_program(argv[i], map);
		i++;
	}
	return (0);
}
