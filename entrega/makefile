# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 21:26:43 by jose-jim          #+#    #+#              #
#    Updated: 2024/10/17 19:59:23 by jose-jim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I -Iinclude.
LFLAGS = -L. -llong_lib -Lmlx-linux -lmlx_Linux -lX11 -lXext
LIB = liblong_lib.a
SRC = $(wildcard src/*.c)#
OBJ = $(SRC:%.c=%.o)
NAME = a
MAIN = image.c

all: $(NAME)

$(NAME): main.o $(LIB)
	$(CC) main.o -L. -llong_lib -Lmlx-linux -lmlx_Linux -lX11 -lXext -o $(NAME)

$(LIB): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

main.o: $(MAIN)  # Use the MAIN variable here
	$(CC) $(CFLAGS) -c $(MAIN) -o main.o

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean