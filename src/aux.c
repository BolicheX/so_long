/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:18:20 by jose-jim          #+#    #+#             */
/*   Updated: 2025/01/21 01:12:42 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_linelen(int fd)
{
	char	buff[BUFFER_SIZE];
	int		bytes;
	int		len;
	int		len_old;

	bytes = 1;
	len = 0;
	len_old = 0;
	while (bytes > 0)
	{
		len = 0;
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		while (buff[len] != '\n' && len < bytes)
			len++;
		len_old = len_old + len;
		if (len < bytes && buff[len] == '\n')
			return (len_old);
	}
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
	data->player_x = game->player_x;
	data->player_y = game->player_y;
	data->heigth = game->n_row;
	data->width = game->n_col;
	data->coll = game->coll;
	data->count = 0;
	data->collected = 0;
	return (*data);
}

//hola

int	ft_random(int col, int row)
{
	int	seed;
	int	random_value;

	seed = (row * 31 + col * 37);
	seed = (16807 * seed) % 2147483647;
	if (seed < 0)
		seed += 2147483647;
	if ((seed % 100) < 60)
		random_value = 0;
	else
		random_value = 1 + (seed % 6);
	return (random_value);
}
