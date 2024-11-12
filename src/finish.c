/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:11:22 by jose-jim          #+#    #+#             */
/*   Updated: 2024/11/12 18:52:03 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int end_program(t_data *data)
{
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int close_window(t_data *data)
{
	end_program(data, 0);
	return 0;
}

int close_esc(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		end_program(data, 0);
		exit(EXIT_SUCCESS);
	}
	return (0);
}