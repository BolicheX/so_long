/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:42:05 by jose-jim          #+#    #+#             */
/*   Updated: 2024/12/19 16:53:21 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int ft_handle_input(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", key);
		ft_end_game(0, data->map, data);
	}
	printf("The %d key has been pressed\n\n", key);
	return (0);
}

int	ft_close(t_data *data)
{
	ft_end_game(0, data->map, data);
	return (0);
}

void	ft_start_game(t_game *game)
{
	t_data	data;

	data = ft_newdata(&data, game);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.width * RES, data.heigth * RES, "so_long");
	if(data.win == NULL)
		ft_end_game("Unable to initialize mlx window", game->map, &data);
	mlx_key_hook(data.win, ft_handle_input, &data);
	mlx_hook(data.win, WIN_CLOSE, 0, ft_close, &data);
	mlx_loop(data.mlx);
}