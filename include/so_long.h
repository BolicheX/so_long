/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:13:46 by jose-jim          #+#    #+#             */
/*   Updated: 2024/11/28 17:19:48 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"

# define RES 32
# define ESC	53
# define W		13
# define A		0
# define S		1
# define D		2

# define MLX_ERROR	1

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <X11/keysym.h>

# include <stdio.h>

typedef struct s_fill
{
	char	**map;
	int		exit;
	int		coll;
}	t_fill;

typedef struct s_game
{
	char	**map;
	int		n_row;
	int		n_col;
	int		exit;
	int		player;
	int		coll;
	int		player_x;
	int		player_y;
	int		endgame;
	t_fill	fill;
}	t_game;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		heigth;
	int		width;
	int		count;
	int		collected;
	t_game	game;
}	t_data;

void	print_char_array(char **arr);
int		ft_error_map(char *msg, char **map_str);
t_game	ft_newgame(void);
void	ft_check_content(t_game *game);
void	ft_check_map(char *map_file, t_game *game);
void	ft_get_map(char *map_file, t_game *game);
void	ft_check_line(char *line, int row, t_game *game);
int		ft_linelen(int fd);

void	ft_validate_path(t_game *game);
void	ft_flood_fill(t_game *game,t_fill *fill, int x, int y);
char	**ft_map_clone(t_game *game);

int	ft_free_map(char **map);

#endif