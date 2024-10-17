/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:13:46 by jose-jim          #+#    #+#             */
/*   Updated: 2024/10/17 21:54:10 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# define ESC	53
# define W		13
# define A		0
# define S		1
# define D		2

#define MLX_ERROR	1

#define WIDTH			1920
#define HEIGHT			1080

#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>
#include "../mlx-linux/mlx.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		depth;
	int		line_length;
	int		endian;
}t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	struct	s_img img;
}t_data;

void my_mlx_pixel_put(t_img *data, int x, int y, int color);
/* finish functions*/
int end_program(t_data *data, int cause);
int close_window(t_data *data);
int close_esc(int keysym, t_data *data);

#endif