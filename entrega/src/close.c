/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:11:22 by jose-jim          #+#    #+#             */
/*   Updated: 2024/10/17 19:56:41 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../long_lib.h"

int close(t_data *data, int cause)
{
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	if (cause == 1)
	{
		printf("ERROR");
		return(MLX_ERROR);
	}
	return (0);
}