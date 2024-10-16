# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 21:26:43 by jose-jim          #+#    #+#              #
#    Updated: 2024/10/16 21:33:22 by jose-jim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -I.
LIB = liblong_lib.a
OBJ = long_lib.o
SRCS = long_lib.c
EXEC = myprogram

all: $(EXEC)

$(EXEC): main.o $(LIB)
	$(CC) main.o -L. -llong_lib -Lmlx-linux -lmlx_Linux -lX11 -lXext -o $(EXEC)

$(LIB): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f $(OBJ) $(LIB) $(EXEC) main.o

.PHONY: all clean