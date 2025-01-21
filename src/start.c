/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:42:05 by jose-jim          #+#    #+#             */
/*   Updated: 2025/01/17 13:14:00 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_handle_input(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		printf("Quiting game.\n");
		ft_end_game(0, data->map, data);
	}
	else if (key == XK_w)
		ft_movement(data, 0, -1);
	else if (key == XK_a)
	{
		//mlx_destroy_image(data->mlx, data->img.mino);
		//ft_img_load(data, &data->img.mino, "sprites/mino_l.xpm");
		data->img.mino = data->img.mino_l;
		ft_movement(data, -1, 0);
	}
	else if (key == XK_s)
		ft_movement(data, 0, +1);
	else if (key == XK_d)
	{
		//mlx_destroy_image(data->mlx, data->img.mino);
		//ft_img_load(data, &data->img.mino, "sprites/mino_r.xpm");
		data->img.mino = data->img.mino_r;
		ft_movement(data, +1, 0);
	}
	return (0);
}

int	ft_close(t_data *data)
{
	ft_printf("Quiting game.\n");
	ft_end_game(0, data->map, data);
	return (0);
}

void	ft_start_game(t_game *game)
{
	t_data	data;

	data = ft_newdata(&data, game);

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.width * RES, data.heigth * RES,
			"so_long");
	if (data.win == NULL)
		ft_end_game("Unable to initialize mlx window", game->map, &data);
	ft_img_init(&data);
	mlx_key_hook(data.win, ft_handle_input, &data);
	mlx_hook(data.win, WIN_CLOSE, 0, ft_close, &data);
	ft_draw_map(&data);
	mlx_loop(data.mlx);
}
