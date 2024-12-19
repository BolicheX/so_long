/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:31:43 by jose-jim          #+#    #+#             */
/*   Updated: 2024/12/19 13:43:49 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_char_array(char **arr)
{
	int i = 0;

    // Iterate over the array of strings
    while (arr[i] != NULL) {
        printf("%s", arr[i]);  // Print each string followed by a newline
        i++;
    }
}

int	main(int argc, char **argv)
{
	t_game	game;

	setbuf(stdout, NULL);
	if (argc != 2)
		ft_error_map("Usage: ./so_long.c <filename>.ber", NULL);
	ft_check_map(argv[1], &game);
	ft_start_game(&game);
	free(game.map);
	return(0);
}