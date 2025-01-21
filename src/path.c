/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:04:55 by jose-jim          #+#    #+#             */
/*   Updated: 2025/01/21 01:30:15 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_validate_path(t_game *game)
{
	t_fill	fill;

	fill.map = ft_map_clone(game);
	fill.coll = 0;
	fill.exit = 0;
	fill.x = game->player_x;
	fill.y = game->player_y;
	ft_flood_fill(game, &fill, fill.x, fill.y);
	ft_free_map(fill.map);
	if (game->coll != fill.coll || game->exit != fill.exit)
		ft_error_map("Map must have a valid path to win", game);
}

char	**ft_map_clone(t_game *game)
{
	char	**clone;
	int		i;

	i = 0;
	clone = ft_calloc(game->n_row + 1, sizeof(char *));
	if (!clone)
		ft_error_map("Error validating map", game);
	while (i < game->n_row && game->map[i])
	{
		clone[i] = ft_strdup(game->map[i]);
		if (!clone)
		{
			ft_free_map(clone);
			ft_error_map("Error validating map", game);
		}
		i++;
	}
	return (clone);
}

void	ft_flood_fill(t_game *game, t_fill *fill, int x, int y)
{
	if (fill->map[y][x] == 'E')
	{
		fill->exit++;
		fill->map[y][x] = 'V';
	}
	if (x < 0 || y < 0 || x >= game->n_col || y >= game->n_row
		|| fill->map[y][x] == '1' || fill->map[y][x] == 'V')
		return ;
	if (fill->map[y][x] == 'C')
		fill->coll++;
	fill->map[y][x] = 'V';
	ft_flood_fill(game, fill, x + 1, y);
	ft_flood_fill(game, fill, x, y +1);
	ft_flood_fill(game, fill, x - 1, y);
	ft_flood_fill(game, fill, x, y - 1);
	return ;
}
