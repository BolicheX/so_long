/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:13:46 by jose-jim          #+#    #+#             */
/*   Updated: 2024/10/28 19:56:49 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#define ESC	53
#define W		13
#define A		0
#define S		1
#define D		2

#define MLX_ERROR	1

#define WIDTH			1920
#define HEIGHT			1080


#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/mlx/mlx.h"
#include "../include/get_next_line/get_next_line.h"
#include "../include/ft_printf/ft_printf.h"
#include <X11/keysym.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		depth;
	int		line_length;
	int		endian;
}t_img;

typedef struct s_map
{
	char	*name;
	int		height;
	int		widht;
	int		player;
	int		collect;
}t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
}t_data;

/* aux functions*/
int	ft_strcmpr(char *s1, char *s2);
void my_mlx_pixel_put(t_img *data, int x, int y, int color);
/* finish functions*/
int end_program(t_data *data, int cause);
int close_window(t_data *data);
int close_esc(int keysym, t_data *data);

#endif