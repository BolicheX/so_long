/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:27:11 by jose-jim          #+#    #+#             */
/*   Updated: 2024/12/19 15:53:00 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_error_map(char *msg, char **map_str)
{
	if (map_str)
		ft_free_map(map_str);
	ft_printf("Error\n%s\n", msg);
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
	if (map_str)
		ft_free_map(map_str);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	if(msg)
	{
		ft_printf("Error\n%s\n", msg);
		exit(EXIT_FAILURE);
	}
	exit(0);
}
