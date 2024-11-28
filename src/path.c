/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:04:55 by jose-jim          #+#    #+#             */
/*   Updated: 2024/11/28 18:17:01 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_map_clone(t_game *game)
{
	char	**clone;
	int		i;

	i = 0;

	clone = ft_calloc(game->n_row + 1, sizeof(char *));
	if (!clone)
		ft_error_map("Error validating map", game->map);
	while (i < game->n_row && game->map[i])
	{
		clone[i] = ft_strdup(game->map[i]);
		if (!clone)
		{
			ft_free_map(clone);
			ft_error_map("Error validating map", game->map);
		}
		i++;
	}
	printf("Clone OK\n");
	return(clone);
}

void	ft_flood_fill(t_game *game, t_fill *fill, int x, int y)
{
	if(x < 0 || y < 0 || x >= game->n_col || y >= game->n_row || game->map[y][x] == '1' || game->map[y][x] == 'V')
		return;
	printf("Map(%d%d)explored\n", x, y);
	if (game->map[y][x] == 'C')
	{
		fill->coll++;
		printf("Colectible reached at(%d%d)\n", x, y);
	}
	if (game->map[y][x] == 'E')
	{
		printf("Exit reached at(%d%d)\n", x, y);
		fill->exit++;
	}
	game->map[y][x] = 'V';
	ft_flood_fill(game, fill, x + 1, y);
	ft_flood_fill(game, fill, x, y +1);
	ft_flood_fill(game, fill, x - 1, y);
	ft_flood_fill(game, fill, x, y - 1);
	return;
}

void	ft_validate_path(t_game *game)
{
	t_fill	fill;
	int	x;
	int	y;

	fill.map = ft_map_clone(game);
	fill.coll = 0;
	fill.exit = 0;
	x = game->player_x;
	y = game->player_y;
	ft_flood_fill(game, &fill, x, y);
	printf("Fill OK\n");
	ft_free_map(fill.map);
	if(game->coll != fill.coll || game->exit != fill.exit)
		ft_error_map("Map must have a valid path to win", game->map);
	printf("Path OK\n");
}
