/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:27:11 by jose-jim          #+#    #+#             */
/*   Updated: 2025/01/20 23:29:04 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_error_map(char *msg, t_game *game)
{
	ft_printf("%sError\n%s%s\n", COLOR_RED, msg, COLOR_DEFAULT);
	if (game && game->map)
	{
		ft_free_map(game->map);
	}
	exit(EXIT_FAILURE);
	return(0);
}

int	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	return(0);
}

int	ft_end_game(char *msg, char **map_str, t_data *data)
{
	if(msg)
		ft_printf("%sError\n%s%s\n", COLOR_RED, msg, COLOR_DEFAULT);
	if (map_str)
		ft_free_map(map_str);
	ft_free_img(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	if(msg)
		{
			free(msg);
			exit(EXIT_FAILURE);
		}
	if(data->collected == data->coll)
		ft_printf("Congratulations! You won!\nFinal Score: %d\n", data->count);
	exit(0);
}

void ft_free_img(t_data *data)
{
	int	i;

	i = 0;
	ft_destroy_img(data->mlx, data->img.mino_l);
	ft_destroy_img(data->mlx, data->img.mino_r);
	while (i < 7)
		ft_destroy_img(data->mlx, data->img.floor[i++]);
	ft_destroy_img(data->mlx, data->img.wall_1);
	ft_destroy_img(data->mlx, data->img.wall_2);
	ft_destroy_img(data->mlx, data->img.exit_c);
	//ft_destroy_img(data->mlx, data->img.exit_o);
	ft_destroy_img(data->mlx, data->img.collect);
}


void	ft_destroy_img(void *mlx_ptr, void *img_ptr)
{
	if (img_ptr)
		mlx_destroy_image(mlx_ptr, img_ptr);
}