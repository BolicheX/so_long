/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:06:06 by jose-jim          #+#    #+#             */
/*   Updated: 2025/01/20 23:18:02 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_draw_map(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (data->map[row])
	{
		col = 0;
		while (data->map[row][col])
		{
			ft_draw_tile(data, row, col);
			col++;
		}
		row++;
	}
}

void	ft_draw_tile(t_data *data, int row, int col)
{
	int	pos_x;
	int	pos_y;

	pos_x = col * RES;
	pos_y = row * RES;
	if (data->map[row][col] == WALL)
		ft_draw_wall(data, row, col);
	if (data->map[row][col] == EMPTY)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.floor[ft_random(col, row)], pos_x, pos_y);
	if (data->map[row][col] == EXIT)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.exit_c, pos_x, pos_y);
	if (data->map[row][col] == COLLECTIBLE)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.collect, pos_x, pos_y);
	if (data->map[row][col] == PLAYER)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.mino, pos_x, pos_y);
}

void	ft_draw_wall(t_data *data, int row, int col)
{
	int	pos_x;
	int	pos_y;

	pos_x = col * RES;
	pos_y = row * RES;
	if (row != data->heigth - 1)
	{
		if (data->map[row + 1][col] != WALL && data->map[row + 1][col] != EXIT)
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.wall_2, pos_x, pos_y);
		else
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.wall_1, pos_x, pos_y);
	}
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.wall_1, pos_x, pos_y);
}
