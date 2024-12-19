/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:18:20 by jose-jim          #+#    #+#             */
/*   Updated: 2024/12/19 16:39:45 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_linelen(int fd)
{
	char	buff[BUFFER_SIZE];
	int		bytes;
	int		len;

	bytes = 1;
	len = 0;
	while (bytes == 1)
	{
		printf("bytes %d\n", bytes);
		bytes = read(fd, buff, BUFFER_SIZE);
		printf("bytes %d\n", bytes);
		printf("buff: %s\n", buff);
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

t_game	ft_newgame(void)
{
	t_game	game;

	game.n_row = 0;
	game.n_col = 0;
	game.exit = 0;
	game.player = 0;
	game.coll = 0;
	game.player_x = 0;
	game.player_y = 0;
	game.endgame = 0;
	return (game);
}

t_data	ft_newdata(t_data *data, t_game *game)
{
	data->map = game->map;
	data->heigth = game->n_row;
	data->width = game->n_col;
	data->count = 0;
	data->collected = 0;
	return (*data);
}