# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 17:24:42 by jjaroens          #+#    #+#              #
#    Updated: 2024/04/28 11:44:26 by jjaroens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = srcs/main.c

INCLUDE = include

# HEADER = $(INCLUDE)/so_long.h
HEADER = minilibx-linux/mlx.h

MLX_PATH = minilibx-linux/

OBJ = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX_PATH)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L$(MLX_PATH) -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	
%.o: %.c
	$(CC) -Wall -Wextra -Werror -I$(HEADER) -Imlx_linux.h -O3 -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(MLX_PATH)obj/*.o


fclean: clean
	rm -f $(NAME)
	make clean -C $(MLX_PATH)
