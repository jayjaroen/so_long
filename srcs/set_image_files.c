/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:25:59 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/18 22:06:34 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_to_render(t_data *data, int y, int x)
{
	// setting the current image position?
	if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->empty_space, 
		x * IMG_SIZE, y * IMG_SIZE);
	else if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall,
		x * IMG_SIZE, y * IMG_SIZE);
	else if (data->map[y][x] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->collectible,
		x * IMG_SIZE, y * IMG_SIZE);
		data->num_collect++;
	}
	else if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit,
		x * IMG_SIZE, y * IMG_SIZE);
	else if (data->map[y][x] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
		x * IMG_SIZE, y * IMG_SIZE);
		data->current_x = x;
		data->current_y = y;
	}
}

void	ft_render_image(t_data *data)
{
	int	x;
	int	y;
	
	ft_printf("this is ft_render_image function\n");
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (data->map[y][x])
		{
			ft_to_render(data, y, x);
			x++;
		}
		y++;
	}
	ft_printf("at the end of ft_render\n");
}

void	ft_set_image(t_data *data)
{
	int	num ;
	
	num = IMG_SIZE;
	if (!data)
		return ;
	ft_printf("this is ft_set_image function\n");
	data->wall = mlx_xpm_file_to_image(data->mlx, "./textures/wall_cactus.xpm", &num, &num);
	data->collectible = mlx_xpm_file_to_image(data->mlx, "./textures/collectible_melon.xpm", &num, &num);
	data->empty_space = mlx_xpm_file_to_image(data->mlx, "./textures/empty_space_tiny_dirt.xpm", &num, &num);
	data->player = mlx_xpm_file_to_image(data->mlx, "./textures/player_panda.xpm", &num, &num);
	data->exit = mlx_xpm_file_to_image(data->mlx, "./textures/exit_pride.xpm", &num, &num);
	if (!data->wall || !data->collectible || !data->empty_space
		|| !data->player || !data->exit)
	{
		ft_printf("Image source not found\n");
		exit(1);
	}	
}