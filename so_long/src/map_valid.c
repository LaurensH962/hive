/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:46:22 by lhaas             #+#    #+#             */
/*   Updated: 2025/01/10 11:04:50 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char *file_name)
{
	int		count;
	int		fd;
	char	c;

	count = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			count++;
	}
	close(fd);
	return (count);
}

void	read_map_helper(t_game *game, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map[i] = gnl_ft_strdup(line);
		if (!game->map[i])
		{
			perror("Error duplicating line");
			while (i > 0)
				free(game->map[--i]);
			free(game->map);
			free(line);
			close(fd);
			exit(EXIT_FAILURE);
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
}

void	read_map_exit(int fd, char *text)
{
	perror(text);
	close(fd);
	exit(EXIT_FAILURE);
}

void	read_map(char *file_name, t_game *game)
{
	int		fd;
	char	*file_comp;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		read_map_exit(fd, "no valid file");
	file_comp = ft_strrchr(file_name, '.');
	if (!file_comp || ft_strncmp(file_comp, ".ber", ft_strlen(file_comp)))
		read_map_exit(fd, "no valid file name");
	game->g_height = count_lines(file_name);
	game->map = (char **)malloc((game->g_height + 1) * sizeof(char *));
	if (!game->map)
	{
		perror("Error allocating map");
		close(fd);
		exit (EXIT_FAILURE);
	}
	read_map_helper(game, fd);
	close(fd);
	valid_map(game);
}
