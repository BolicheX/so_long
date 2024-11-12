/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:35:40 by jose-jim          #+#    #+#             */
/*   Updated: 2024/11/12 19:28:07 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_map(char **argv, t_map *map)
{
	int	fd;
	if (fd = open(argv[1], O_RDONLY) < 0)
		ft_error_map("Unable to read file");
	if (ft_strrncmp(argv[1], ".ber", 4))
		ft_error_map("Invalid file type, use .ber", NULL);
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