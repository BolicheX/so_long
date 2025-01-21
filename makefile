# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 21:26:43 by jose-jim          #+#    #+#              #
#    Updated: 2025/01/17 14:39:39 by jose-jim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The name of the executable
NAME = so_long

# Compilation flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
# Linker flags : 'libft', 'mlx' and 'mlx' for Linux, 'lib' for X Window System, 'xext' for a single extension, and 'lm' for the math library
LFLAGS = -lft -lmlx -lmlx_Linux -lX11 -lXext -lm

# Command to remove files/directories
REMOVE = rm -rf
# Command to create directories
MKDIR = mkdir -p

# Path variables
SRCS_PATH =  ./src/
OBJS_PATH = ./objs/
LIBS_PATH = ./libs/
HEADER_PATH = ./include/

# Path to libraries
LIBFT_PATH = $(LIBS_PATH)libft/
MLX_PATH = $(LIBS_PATH)mlx/

# Source files
SRC = $(wildcard $(SRCS_PATH)*.c)

# Object files
OBJS = $(patsubst $(SRCS_PATH)%.c, $(OBJS_PATH)%.o, $(SRC))

# Compiler flags to include library headers
INCLUDES = -I $(LIBFT_PATH) -I $(MLX_PATH)
# Compiler flags to link to libraries
LINK_LIBS = -L$(LIBFT_PATH) -L$(MLX_PATH)

# Color codes for terminal output
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all : $(NAME)

# The target to build the mandatory part
$(NAME) : $(OBJS)
		@make -C $(LIBFT_PATH) --no-print-directory
		@make -C $(MLX_PATH) > /dev/null 2>&1
		@echo "$(GREEN) [MLX] Library compiled $(DEF_COLOR)"
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LINK_LIBS) $(LFLAGS)
		@echo "$(GREEN) The Makefile of [SO_LONG] has been compiled!$(DEF_COLOR)"

# Compiles C source files into object files
$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@$(MKDIR) $(OBJS_PATH)
	@$(CC) $(CFLAGS) -I $(HEADER_PATH) -c $< -o $@


clean :
	@$(REMOVE) $(OBJS_PATH)
	@make clean -C $(LIBFT_PATH) --no-print-directory
	@make clean -C $(MLX_PATH) > /dev/null 2>&1
	@echo "$(BLUE)[SO_LONG] Object files cleaned!$(DEF_COLOR)"

fclean : clean
	@$(REMOVE) $(NAME) $(OBJS_PATH)
	@make fclean -C $(LIBFT_PATH) --no-print-directory
	@echo "$(BLUE)[SO_LONG] Executable files and directories cleaned!$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re