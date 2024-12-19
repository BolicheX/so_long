/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:35:40 by jose-jim          #+#    #+#             */
/*   Updated: 2024/12/19 14:44:29 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_content(t_game *game)
{
	if (game->player != 1)
		ft_error_map("Map must contain 1 player", NULL);
	if (game->exit != 1)
		ft_error_map("Map must contain 1 exit", NULL);
	if (game->coll < 1)
		ft_error_map("Map must containt at least 1 collectible", NULL);
	printf("Content OK\n");
}

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
	close(fd);
	game->map = calloc(game->n_row + 1, sizeof(char *));
	ft_printf("rows:%d, Columns: %d\n", game->n_row, game->n_col);
	ft_get_map(map_file, game);
	ft_check_content(game);
	ft_validate_path(game);
	ft_printf("map valid!\n");
}

void	ft_get_map(char *map_file, t_game *game)
{
	int		row;
	int		fd;
	char	*line;

	row = 0;
	game->map = ft_calloc(game->n_row + 1, sizeof(char *));
	if (!game->map)
		ft_error_map("Bad map memory allocation", NULL);
	fd = open(map_file, O_RDONLY);
	while(row < game->n_row)
	{
		line = get_next_line(fd);
		if (line)
		{
			game->map[row] = line;
			ft_check_line(game->map[row], row, game);
		}
		row++;
	}
	ft_printf("\nplayers:%d, exits:%d, collectibles:%d\n", game->player, game->exit, game->coll);
}

void	ft_check_line(char *line, int row, t_game *game)
{
	int	i;

	i = 0;
	printf("Checking line:>%s", line);
	while (line[i] != '\n' && line[i])
	{
		if (!(ft_strchr("01CPE", line[i])))
			ft_error_map("Map must be made with only '0','1','C','P','E'", game->map);
		if ((row == 0 || row == game->n_row - 1 || i == 0 || i == game->n_col - 1) && line[i] != '1')
			ft_error_map("Map must be enclosed by walls '1'", game->map);
		if (line[i] == 'P')
		{
			game->player += 1;
			game->player_x = i;
			game->player_y = row;
		}
		if (line[i] == 'E')
			game->exit += 1;
		if (line[i] == 'C')
			game->coll += 1;
		i++;
	}
	if (i != game->n_col)
		ft_error_map("Map not rectangular", game->map);
}
