/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:31:43 by jose-jim          #+#    #+#             */
/*   Updated: 2025/01/21 01:27:23 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error_map("Usage: ./so_long.c <filename>.ber", NULL);
	ft_check_map(argv[1], &game);
	ft_start_game(&game);
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
