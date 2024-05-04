/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:07:03 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/04 17:44:42 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "../include/so_long.h"
// #include "../minilibx_opengl_20191021/mlx.h"

// the number of ESC -> exit key && exit && free, free window
// 65307	esc
// 119	w || 87 W	|| 65362 up
// 97	a || 65 A	|| 65361 down
// 115	s || 85 S	|| 65364 left
// 100	d || 68 D	|| 65363 right

// ChatGPT
/*Up Arrow: U+2191 → Decimal: 8593
Down Arrow: U+2193 → Decimal: 8595
Left Arrow: U+2190 → Decimal: 8592
Right Arrow: U+2192 → Decimal: 8594*/

void	ft_move_player(int y, int x, t_data *data)
{
	ft_printf("I am not at ft_move_player\n");
	if (data->map[data->current_y + y][data->current_x + x] == '1')
		return ;
	else if (data->map[data->current_y + y][data->current_x + x] == 'E')
	{
		if (!data->num_collect)
		{
			// collect completed && exit game
			// write function to exit the game
		}
		else
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit, data->current_x * 100, data->current_y * 100);
			return ; // can't move to the wall
		}
	}
	else if (data->map[data->current_y + y][data->current_x + x] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->empty_space, data->current_x *100, data->current_y *100);
	data->current_x += x;
	data->current_y += y;
	data->num_moves += 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, data->current_x *100, data->current_y *100);
	ft_printf("the number of moves are: %d\n", data->num_moves);
}

int	ft_check_key_input(int key, t_data *data)
{
	ft_printf("I am at ft_check_key_input\n");
	if (key == 65307)
	{
		// function exit game;
		// free data in window
		return (1);
	}
	else if (key == 119 || key == 87 || key == 65362)
	{
		// write function moving the player position up// only player move
		// move up (y - 1, x stay the same postion 0)
		ft_move_player(-1, 0, data);
	}
	else if (key == 97 || key == 65 || key == 65361)
	{
		// write function moving the player position down
		// move down (y + 1, x stay the same position 0) 
		ft_move_player(1, 0, data);
	}
	else if (key == 115 || key == 85 || key == 65364)
	{
		// write a function moving the player position leftside
		// move left (y= 0, x -1 )
		ft_move_player(0, -1, data);
	}
	else if (key == 100 || key == 68 || key == 65363)
	{
		// move right (y = 0, x + 1) 
		ft_move_player(0, 1, data);
	}
	return (0);
}

void	ft_make_move(t_data *data)
{
	ft_printf("I am at ft_make_move\n");
	mlx_hook(data->mlx_win, 2, (1L << 0), ft_check_key_input, data);
}