/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:35:58 by jose-jim          #+#    #+#             */
/*   Updated: 2025/01/20 23:34:08 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_movement(t_data *data, int x, int y)
{
	int			new_x;
	int			new_y;

	new_x = data->player_x + x;
	new_y = data->player_y + y;
	if (data->map[new_y][new_x] != WALL)
	{
		if (data->map[new_y][new_x] == COLLECTIBLE)
		{
			data->collected++;
			if (data->collected == data->coll)
				{
					ft_destroy_img(data->mlx, data->img.exit_c);
					//data->img.exit_c = data->img.exit_o;
					ft_img_load(data, &data->img.exit_c, "sprites/door_o.xpm");
					ft_draw_map(data);
					ft_printf("Exit open\n");
				}
		}
		if (data->map[new_y][new_x] == EXIT && data->collected == data->coll)
			ft_end_game(0, data->map, data);
		if (data->map[new_y][new_x] != EXIT)
			ft_move_ok(data, new_y, new_x);
	}

}
void	ft_move_ok(t_data *data, int new_y, int new_x)
{
	static int	old_count;

	old_count = data->count;
	data->map[new_y][new_x] = PLAYER;
	data->map[data->player_y][data->player_x] = EMPTY;
	ft_draw_tile(data, data->player_y, data->player_x);
	data->player_x = new_x;
	data->player_y = new_y;
	ft_draw_tile(data, data->player_y, data->player_x);
	data->count++;
	if (data->count != old_count)
		ft_printf("Movements: %d\n", data->count);
	//ft_printf("char pos:%d-%d", new_x, new_y);
}

