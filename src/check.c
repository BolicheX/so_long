/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:35:40 by jose-jim          #+#    #+#             */
/*   Updated: 2025/01/21 15:43:23 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_map(char *map_file, t_game *game)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error_map("Unable to read file", NULL);
	if (ft_strrncmp(map_file, ".ber", 4))
		ft_error_map("Invalid file type, use .ber", NULL);
	*game = ft_newgame();
	game->n_row = ft_countlines_fd(fd);
	close(fd);
	fd = open(map_file, O_RDONLY);
	game->n_col = ft_linelen(fd);
	if (game->n_col == 0)
		ft_error_map("Map invalid, only has one line", NULL);
	close(fd);
	ft_get_map(map_file, game);
	ft_check_content(game);
	ft_validate_path(game);
}

void	ft_get_map(char *map_file, t_game *game)
{
	int		row;
	int		fd;

	row = 0;
	game->map = ft_calloc(game->n_row + 1, sizeof(char *));
	if (!game->map)
		ft_error_map("Bad map memory allocation", NULL);
	fd = open(map_file, O_RDONLY);
	while (row < game->n_row)
		game->map[row++] = get_next_line(fd);
	row = 0;
	while (row < game->n_row)
	{
		ft_check_line(game->map[row], row, game);
		row++;
	}
	close(fd);
}

void	ft_check_line(char *line, int row, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i])
	{
		if (!(ft_strchr("01CPE", line[i])))
			ft_error_map("Map must only contain '0','1','C','P','E'",
				game);
		if ((row == 0 || row == game->n_row - 1 || i == 0
				|| i == game->n_col - 1) && line[i] != '1')
			ft_error_map("Map must be enclosed by walls '1'", game);
		ft_check_char(line[i], i, row, game);
		i++;
	}
	if (i != game->n_col)
		ft_error_map("Map not rectangular", game);
}

void	ft_check_char(char c, int i, int row, t_game *game)
{
	if (c == 'P')
	{
		game->player += 1;
		game->player_x = i;
		game->player_y = row;
	}
	if (c == 'E')
		game->exit += 1;
	if (c == 'C')
		game->coll += 1;
}

void	ft_check_content(t_game *game)
{
	if (game->player != 1)
		ft_error_map("Map must contain 1 player", game);
	if (game->exit != 1)
		ft_error_map("Map must contain 1 exit", game);
	if (game->coll < 1)
		ft_error_map("Map must containt at least 1 collectible", game);
}
