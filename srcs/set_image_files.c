/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:25:59 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/11 15:09:23 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "../include/so_long.h"
// #include "../minilibx_opengl_20191021/mlx.h"

// create a variable later
void	ft_to_render(t_data *data, int y, int x)
{
	// setting the current image position?
	if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->empty_space, 
		x * 100, y * 100);
	else if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall,
		x * 100, y * 100);
	else if (data->map[y][x] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->collectible,
		x * 100, y * 100);
		data->num_collect++;
	}
	else if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit,
		x * 100, y * 100);
	else if (data->map[y][x] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
		x * 100, y * 100);
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
	while (y < data->map_heigth)
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
	
	num = 100;
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