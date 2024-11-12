/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:31:43 by jose-jim          #+#    #+#             */
/*   Updated: 2024/11/12 18:39:13 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;
	t_game	game;

	if (argc != 2)
		ft_error_map("Usage: ./so_long.c <filename>.ber", NULL);
	map.content = ft_check_map(argv, &game);
}