# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 21:26:43 by jose-jim          #+#    #+#              #
#    Updated: 2024/10/28 21:12:32 by jose-jim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADERS =	src/so_long.h \
			include/get_next_line/get_next_line.h \
			include/ft_printf/ft_printf.h \
			include/mlx/mlx.h \

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude.
LFLAGS = -Linclude/mlx -lmlx_Linux -lX11 -lXext

DIR_OBJ = obj
SRC = $(wildcard src/*.c) \
	$(wildcard include/get_next_line/*.c) \
	$(wildcard include/ft_printf/*.c)
OBJECTS = $(addprefix $(DIR_OBJ)/,$(notdir $(SRC:.c=.o)))

MLX_PATH = ./include/mlx/

vpath %.c src include/ft_printf include/get_next_line

all: make_libs make_dir $(NAME)

make_dir:
	@mkdir -p $(DIR_OBJ)

make_libs:
	@make -C $(MLX_PATH) all > /dev/null 2>&1
	@echo "minilibx compiled!\n"

$(NAME): $(OBJECTS) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LFLAGS) -o $(NAME)
	@echo "so_long compiled!\n"

$(DIR_OBJ)/%.o: %.c $(HEADERS) | make_dir
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	@rm -rf $(DIR_OBJ)
	@make -C $(MLX_PATH) clean > /dev/null 2>&1
	@echo "Removed object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Removed executable"

re: fclean all

.PHONY: all clean fclean re make_dir make_libs