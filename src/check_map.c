/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:35:40 by jose-jim          #+#    #+#             */
/*   Updated: 2024/10/31 17:31:51 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	get_map(map_file, data);
	if (check_rectangular(*data) == 1)
		err_rectangular(data, file_name);
	if (check_characters(*data) == 0)
		err_characters(data, file_name);
	if (check_player(*data) == 0)
		err_player(data, file_name);
	if (check_walls(data) != 0)
		err_walls(data, file_name);
	if (check_ecp(*data) == 0)
		err_ecp(data, file_name);
	get_collectibles(data);
	get_player_position(data);
	return (1);
}