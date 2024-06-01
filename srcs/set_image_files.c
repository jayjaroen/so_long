/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:25:59 by jjaroens          #+#    #+#             */
/*   Updated: 2024/06/01 11:45:18 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_to_render(t_data *data, int y, int x)
{
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
}

void	ft_set_image(t_data *data)
{
	int	num ;

	num = IMG_SIZE;
	if (!data->mlx)
	{
		ft_free_map(data);
		exit (1);
	}
	data->wall = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall_cactus.xpm", &num, &num);
	data->collectible = mlx_xpm_file_to_image(data->mlx,
			"./textures/collectible_melon.xpm", &num, &num);
	data->empty_space = mlx_xpm_file_to_image(data->mlx,
			"./textures/empty_space_tiny_dirt.xpm", &num, &num);
	data->player = mlx_xpm_file_to_image(data->mlx,
			"./textures/player_panda.xpm", &num, &num);
	data->exit = mlx_xpm_file_to_image(data->mlx,
			"./textures/exit_pride.xpm", &num, &num);
	if (!data->wall || !data->collectible || !data->empty_space
		|| !data->player || !data->exit)
	{
		ft_putstr_fd("Error: Image sources not found\n", 2);
		ft_free_map(data);
		exit(EXIT_FAILURE);
	}
}
