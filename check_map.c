/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:35:40 by jose-jim          #+#    #+#             */
/*   Updated: 2024/10/28 18:47:27 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(const char	*name, const char	*ext)
{
	size_t	n_len;
	size_t	e_len;

	if (ft_strcmpr(name))
}

void	check_map(char *map_file, t_data *data)
{
	if (check_extension(map_file, ".ber") != 0)
		err_extension(map_file);
	get_map(map_file, game);
	if (check_rectangular(*game) == 1)
		err_rectangular(game, file_name);
	if (check_characters(*game) == 0)
		err_characters(game, file_name);
	if (check_player(*game) == 0)
		err_player(game, file_name);
	if (check_walls(game) != 0)
		err_walls(game, file_name);
	if (check_ecp(*game) == 0)
		err_ecp(game, file_name);
	get_collectibles(game);
	get_player_position(game);
}