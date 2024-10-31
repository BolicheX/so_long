/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:31:43 by jose-jim          #+#    #+#             */
/*   Updated: 2024/10/31 17:33:40 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_error_map(1);
	data.mlx = mlx_init();
	if (!data.mlx)
		end_program(&data, 1);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "My Window");
	data.img.img = mlx_xpm_file_to_image(data.mlx, relative_path, &img_width, &img_height);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.depth, &data.img.line_length, &data.img.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 32, 32);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_key_hook(data.win, close_esc, &data);
	mlx_loop(data.mlx);
	return 0;
}