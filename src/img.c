/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:00:15 by jose-jim          #+#    #+#             */
/*   Updated: 2025/01/20 23:39:35 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_img_load(t_data *data, void **img, char *path)
{
	int		res;
	char	*error;

	res = RES;
	*img = NULL;
	*img = mlx_xpm_file_to_image(data->mlx, path, &res, &res);
	if (*img == NULL)
	{
		error = ft_strjoin("Unable to load texture: ", path);
		ft_end_game(error, data->map, data);
	}
}

void	ft_img_init(t_data *data)
{
	//ft_img_load(data, &data->img.mino, "sprites/mino_r.xpm");
	ft_img_new(data);
	ft_img_load(data, &data->img.mino_r, "sprites/mino_r.xpm");
	ft_img_load(data, &data->img.mino_l, "sprites/mino_l.xpm");
	ft_img_load(data, &data->img.floor[0], "sprites/bg.xpm");
	ft_img_load(data, &data->img.floor[1], "sprites/bg1.xpm");
	ft_img_load(data, &data->img.floor[2], "sprites/bg2.xpm");
	ft_img_load(data, &data->img.floor[3], "sprites/bg3.xpm");
	ft_img_load(data, &data->img.floor[4], "sprites/bg4.xpm");
	ft_img_load(data, &data->img.floor[5], "sprites/bg5.xpm");
	ft_img_load(data, &data->img.floor[6], "sprites/bg6.xpm");
	ft_img_load(data, &data->img.wall_1, "sprites/wall_1.xpm");
	ft_img_load(data, &data->img.wall_2, "sprites/wall_2.xpm");
	//ft_img_load(data, &data->img.exit_o, "sprites/door_o.xpm");
	ft_img_load(data, &data->img.exit_c, "sprites/door_c.xpm");
	ft_img_load(data, &data->img.collect, "sprites/diary.xpm");
	data->img.mino = data->img.mino_r;
	//ft_printf("Textures loaded\n");
}

void ft_img_new(t_data *data)
{
	int	i;

	i = 0;
	data->img.mino_l = NULL;
	data->img.mino_r = NULL;
	while (i < 7)
		data->img.floor[i++] = NULL;
	data->img.wall_1 = NULL;
	data->img.wall_2 = NULL;
	data->img.exit_c = NULL;
	//data->img.exit_o = NULL;
	data->img.collect = NULL;
}