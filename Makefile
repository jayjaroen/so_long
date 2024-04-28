# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 17:24:42 by jjaroens          #+#    #+#              #
#    Updated: 2024/04/28 15:19:12 by jjaroens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = srcs/main.c

LIBFT = ./libft/libft.a 

INCLUDE = include

HEADER_SO = $(INCLUDE)/so_long.h

HEADER = minilibx-linux/mlx.h

MLX_PATH = minilibx-linux/

OBJ = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT):
	make -C ./libft
	
$(NAME): $(OBJ) $(LIBFT) $(HEADER_SO)
	make -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -Lmlx_linux -lmlx_Linux -L$(MLX_PATH) -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) 
# linux version of MLX
	
%.o: %.c $(HEADER_SO)
	$(CC) $(CFLAGS) -I$(HEADER) -Imlx_linux.h -O3 -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(MLX_PATH)obj/*.o


fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)
	make clean -C $(MLX_PATH)

norminette:
	@norminette -R CheckForbiddenSourceHeader srcs/*.c
	@norminette -R CheckForbiddenSourceHeader libft/*.c
	@norminette -R CheckDefine libft/libft.h
	@norminette -R CheckDefine $(INCLUDE)/*.h