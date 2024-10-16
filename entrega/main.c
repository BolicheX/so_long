/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:11:26 by jose-jim          #+#    #+#             */
/*   Updated: 2024/10/16 21:34:50 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long_lib.h"

#define MLX_ERROR	1
#define WIDTH			1920
#define HEIGHT			1080


void	create_image(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;  // Reset x for each new row
		while (x < WIDTH)
		{
			if (x % 2 == 0)
				my_mlx_pixel_put(&data->img, x, y, 0xFF0000); // Draw red pixel at (x, y) if x is even
			x++;
		}
		y++;
	}
}

int handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(data->mlx,data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	else if (keysym == XK_space)
		create_image(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if(data.mlx == NULL)
		return (MLX_ERROR);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "My Window");
	if(data.win == NULL)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (MLX_ERROR);
	}
	data.img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.depth, &data.img.line_length, &data.img.endian);

	mlx_key_hook(data.win, handle_input, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img.img);
	return 0;
}