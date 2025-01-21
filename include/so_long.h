/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:13:46 by jose-jim          #+#    #+#             */
/*   Updated: 2025/01/21 01:41:22 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"

# define RES 32
# define ESC	53
# define WIN_CLOSE 17
# define W		13
# define A		0
# define S		1
# define D		2

# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'

# define COLOR_RED "\033[0;31m"
# define COLOR_DEFAULT "\033[0;39m"

# define MLX_ERROR	1

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <X11/keysym.h>

# include <stdio.h>

typedef struct s_img
{
	void	*mino;
	void	*mino_r;
	void	*mino_l;
	void	*floor[7];
	void	*wall_1;
	void	*wall_2;
	void	*exit_c;
	void	*collect;
}				t_img;

typedef struct s_fill
{
	char	**map;
	int		exit;
	int		coll;
	int		x;
	int		y;
}	t_fill;

typedef struct s_game
{
	char	**map;
	int		n_row;
	int		n_col;
	int		exit;
	int		player;
	int		player_x;
	int		player_y;
	int		coll;
	int		endgame;
	t_fill	fill;
}	t_game;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	int		player_x;
	int		player_y;
	int		heigth;
	int		width;
	int		count;
	int		coll;
	int		collected;
	t_img	img;
}	t_data;

// Start and call game functions
void	ft_start_game(t_game *game);
// Check for map validity and populate map matrix and game elements
void	ft_check_map(char *map_file, t_game *game);
void	ft_get_map(char *map_file, t_game *game);
void	ft_check_line(char *line, int row, t_game *game);
void	ft_check_char(char c, int i, int row, t_game *game);
void	ft_check_content(t_game *game);
// Valid path search algorithm
void	ft_validate_path(t_game *game);
char	**ft_map_clone(t_game *game);
void	ft_flood_fill(t_game *game, t_fill *fill, int x, int y);
// Initialize map and game structures
t_game	ft_newgame(void);
t_data	ft_newdata(t_data *data, t_game *game);
// Init, load and transform .xpm, files into xlm images
void	ft_img_new(t_data *data);
void	ft_img_init(t_data *data);
void	ft_img_load(t_data *data, void **img, char *path);
void	ft_free_img(t_data *data);
void	ft_destroy_img(void *mlx_ptr, void *img_ptr);
// Draw and update tiles around ther map
void	ft_draw_map(t_data *data);
void	ft_draw_tile(t_data *data, int row, int col);
void	ft_draw_wall(t_data *data, int row, int col);
// Auxiliary functions
int		ft_linelen(int fd);
int		ft_random(int col, int row);
// Manage the input and player movement
int		ft_handle_input(int key, t_data *data);
void	ft_movement(t_data *data, int x, int y);
void	ft_move_ok(t_data *data, int new_y, int new_x);
// To close the program, in case of error, win or manual close
int		ft_close(t_data *data);
int		ft_end_game(char *msg, char **map_str, t_data *data);
int		ft_free_map(char **map);
int		ft_error_map(char *msg, t_game *game);

#endif