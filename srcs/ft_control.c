/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:07:03 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/25 13:12:59 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// the number of ESC -> exit key && exit && free, free window
// 65307	esc
// 119	w || 87 W	|| 65362 up
// 97	a || 65 A	|| 65361 right
// 115	s || 85 S	|| 65364 left
// 100	d || 68 D	|| 65363 down

void	ft_check_finish_game(int y, int x, t_data *data)
{
	if (data->map[data->current_y][data->current_x] == 'E'
		&& !data->num_collect)
	{
		ft_printf("Panda is saved! Yeah!\n");
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->empty_space,
			data->current_x * IMG_SIZE, data->current_y * IMG_SIZE);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
			(data->current_x + x) * IMG_SIZE, (data->current_y + y) * IMG_SIZE);
		ft_exit_game(data);
	}
}

void	ft_move_player_cont(t_data *data)
{
	if (data->map[data->current_y][data->current_x] == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->empty_space, data->current_x * IMG_SIZE,
			data->current_y * IMG_SIZE);
	if (data->map[data->current_y][data->current_x] == 'C')
	{
		data->map[data->current_y][data->current_x] = '0';
		data->num_collect--;
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->empty_space, data->current_x * IMG_SIZE,
			data->current_y * IMG_SIZE);
	}
}

void	ft_move_player(int y, int x, t_data *data)
{
	if (data->map[data->current_y + y][data->current_x + x] == '1')
		return ;
	if (data->map[data->current_y][data->current_x] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit,
			data->current_x * IMG_SIZE, data->current_y * IMG_SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->empty_space, data->current_x * IMG_SIZE,
			data->current_y * IMG_SIZE);
	data->current_x += x;
	data->current_y += y;
	data->num_moves++;
	ft_move_player_cont(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
		data->current_x * IMG_SIZE, data->current_y * IMG_SIZE);
	ft_printf("the number of moves are: %d\n", data->num_moves);
	ft_check_finish_game(data->current_y, data->current_x, data);
}

// int	ft_check_key_input(int key, t_data *data)
// {
// 	if (key == KEY_UP || key == KEY_W || key == KEY_w)
// 		ft_move_player(-1, 0, data);
// 	else if (key == KEY_DOWN || key == KEY_S || key == KEY_s)
// 		ft_move_player(1, 0, data);
// 	else if (key == KEY_LEFT || key == KEY_A || key == KEY_a)
// 		ft_move_player(0, -1, data);
// 	else if (key == KEY_RIGHT || key == KEY_D || key == KEY_d)
// 		ft_move_player(0, 1, data);
// 	return (0);
// }

// void	ft_make_move(t_data *data)
// {
// 	mlx_hook(data->mlx_win, 2, (1L << 0), &ft_check_key_input, data);
// 	mlx_hook(data->mlx_win, 17, (1L << 17), &ft_exit_game, data);
// }

/////////////////MAC///
int	ft_check_key_input(int key, t_data *data)
{
	// ft_printf("%d\n", key);
	// (void *)data;	
	// return (key);
	if (key == 53) // ESC
	{
		// function exit game;
		ft_exit_game(data);
		return (1);
	}
	else if (key == 126 ) // up
	{
		// write function moving the player position up// only player move
		// move up (y - 1, x stay the same postion 0)
		ft_move_player(-1, 0, data);
	}
	else if (key == 125 ) 
	{
		// write function moving the player position down
		// move down (y + 1, x stay the same position 0)
		// still have problem with downward error
		ft_move_player(1, 0, data);
	}
	else if (key == 123)
	{
		// write a function moving the player position leftside
		// move left (y= 0, x -1 )
		ft_move_player(0, -1, data);
	}
	else if (key == 124)
	{
		// move right (y = 0, x + 1) 
		ft_move_player(0, 1, data);
	}
	return (0);
}

void	ft_make_move(t_data *data)
{
	ft_printf("I am at ft_make_move\n");
	ft_printf("%d\n", mlx_hook(data->mlx_win, 2, 0, ft_check_key_input, data));
	// does the second and third variables depending the assignment?
	mlx_hook(data->mlx_win, 17, 0, ft_exit_game, data);
}