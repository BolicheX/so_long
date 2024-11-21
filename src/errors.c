/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:27:11 by jose-jim          #+#    #+#             */
/*   Updated: 2024/11/21 17:04:14 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_error_map(char *msg, char **map_str)
{
	if (map_str)
		free(*map_str);
	ft_printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
	return (0);
}
