/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:35:40 by jose-jim          #+#    #+#             */
/*   Updated: 2024/11/21 17:44:41 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game	ft_newgame(void)
{
	t_game	game;

	game.n_row = 0;
	game.n_col = 0;
	game.n_exit = 0;
	game.n_pl = 0;
	game.n_coll = 0;
	game.endgame = 0;
	return (game);
}

void	ft_check_content(t_game *game)
{
	if (game->n_pl != 1)
		ft_error_map("Map must contain 1 start position", NULL);
	if (game->n_exit != 1)
		ft_error_map("Map must contain 1 exit", NULL);
	if (game->n_coll <= 1)
		ft_error_map("Map must containt at least 1 collectible", NULL);
}

char	**ft_check_map(char *map_file, t_game *game)
{
	int		fd;
	char	**map;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error_map("Unable to read file", NULL);
	if (ft_strrncmp(map_file, ".ber", 4))
		ft_error_map("Invalid file type, use .ber", NULL);
	*game = ft_newgame();
	map = ft_get_map(fd, game);
	close(fd);
	return (map);
}

int	ft_linelen(int fd)
{
	char	buff[BUFFER_SIZE];
	int		bytes;
	int		len;

	bytes = 1;
	len = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		while (buff[len] && buff[len] != '\n')
			len++;
		if (buff[len] == '\n')
			return (len);
		else
			break;
	}
	ft_error_map("Map invalid", NULL);
	return (0);
}

char	**ft_get_map(int fd, t_game *game)
{
	char	*line;
	int		row;

	row = 0;
	game->n_row = ft_countlines_fd(fd);
	game->n_col = ft_linelen(fd);
	game->map = ft_calloc(game->n_row + 1, sizeof(char *));
	if (!game->map)
		ft_error_map("Map memory allocation failed", NULL);
	ft_printf("rows:%d, Columns: %d\n", game->n_row, game->n_col);
	while(row < game->n_row)
	{
		line = get_next_line(fd);
		printf("%s", line);
		row++;
	}
	ft_printf("players:%d, exits:%d, collectibles:%d\n", game->n_pl, game->n_exit, game->n_coll);
	ft_check_content(game);
	return(game->map);
}

void	ft_count_content(char c, t_game *game)
{
	if (c == 'P')
		game->n_pl += 1;
	if (c == 'E')
		game->n_exit += 1;
	if (c == 'C')
		game->n_coll += 1;
}

void	ft_check_line(char *line, int row, t_game *game)
{
	int	i;

	i = 0;
	if ((int)ft_strlen(line) -1 != game->n_col)
		ft_error_map("Map not rectangular", NULL);
	while (line[i] && i < game->n_col - 1)
	{

		if ((row == 0 || row == game->n_row -1 || i == 0 || i == game->n_col -1) && line[i] != '1')
			ft_error_map("Map must be enclosed by walls '1'", NULL);
		if (line[i] == 'P' || line[i] == 'E' || line[i] == 'C')
			ft_count_content(line[i], game);
		else if (line[i] != '0' && line[i] != '1')
			ft_error_map("Map must be made with only '0','1','C','P','E'", NULL);
		i++;
	}
	return ;
}
