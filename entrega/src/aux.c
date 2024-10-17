/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:32:54 by jose-jim          #+#    #+#             */
/*   Updated: 2024/10/17 19:56:36 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../long_lib.h"

void my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->depth / 8));
    *(unsigned int*)dst = color;
}