# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 17:24:42 by jjaroens          #+#    #+#              #
#    Updated: 2024/05/11 15:43:00 by jjaroens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = srcs/main.c srcs/set_image_files.c srcs/ft_control.c \
		srcs/exit_game.c srcs/check_map.c srcs/map_conditions_valid.c

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

################################# MAC ########################################

# CFLAGS= -I$(INC) -O3 -I..

# NAME = so_long

# HEADERS_LIST = include/so_long.h

# SRC = srcs/main.c srcs/set_image_files.c srcs/ft_control.c \
# 		srcs/exit_game.c srcs/check_map.c srcs/map_conditions_valid.c

# OBJ = $(SRC:%.c=%.o)

# LFLAGS = -Lminilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit -o

# all: $(NAME)

# $(NAME): $(OBJ) $(HEADERS_LIST)
# 	$(MAKE) -C libft
# 	$(CC) $(OBJ) ./libft/libft.a $(LFLAGS) $(NAME)

# clean:
# 	rm -f $(NAME) $(OBJ)

# fclean: clean
# 	make fclean -C libft

# re: fclean all

# .PHONY: clean fclean all re
