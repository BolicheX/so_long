# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 21:26:43 by jose-jim          #+#    #+#              #
#    Updated: 2024/10/17 22:20:32 by jose-jim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude.
LFLAGS = -Lmlx-linux -lmlx_Linux -lX11 -lXext
DIR_OBJ = obj
SRC = $(wildcard src/*.c)
OBJECTS = $(addprefix $(DIR_OBJ)/,$(notdir $(SRC:.c=.o)))
NAME = so_long
LIB = $(DIR_OBJ)/so_long.a

all: make_dir $(NAME)

make_dir:
	@mkdir -p $(DIR_OBJ)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LFLAGS) -o $(NAME)

$(DIR_OBJ)/%.o: src/%.c | make_dir
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB): $(OBJECTS)
	ar rcs $@ $^

clean:
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re make_dir