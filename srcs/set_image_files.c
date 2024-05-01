/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:25:59 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/01 20:44:35 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "../include/so_long.h"
#include "../minilibx_opengl_20191021/mlx.h"

// create a variable later
void	ft_to_render(t_data *data, int y, int x)
{
	// setting the current image position?
	ft_printf("this is ft_to_render function\n");
	if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->empty_space, 
		x * 100, y * 100);
	else if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall,
		x * 100, y * 100);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->collectible,
		x * 100, y * 100); // Do I need update this?
	else if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit,
		x * 100, y * 100);
	else if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
		x * 100, y * 100);
	ft_printf("at the end of ft_to_render\n");
}

void	ft_render_image(t_data *data)
{
	int	x;
	int	y;
	// int	width;
	int	heigth;
	// current width = 13
	// current heigth = 5
	ft_printf("this is ft_render_image function\n");
	y = 0;
	// width = 13;
	heigth = 5;
	while (y < heigth)
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
	data->wall = mlx_xpm_file_to_image(data->mlx, "./sprites/wall_cactus.xpm", &num, &num);
	data->collectible = mlx_xpm_file_to_image(data->mlx, "./sprites/collectible_melon.xpm", &num, &num);
	data->empty_space = mlx_xpm_file_to_image(data->mlx, "./sprites/empty_space_tiny_dirt.xpm", &num, &num);
	data->player = mlx_xpm_file_to_image(data->mlx, "./sprites/player_panda.xpm", &num, &num);
	data->exit = mlx_xpm_file_to_image(data->mlx, "./sprites/exit_pride.xpm", &num, &num);
	if (!data->wall || !data->collectible || !data->empty_space
		|| !data->player || !data->exit)
	{
		ft_printf("Image source not found\n");
		exit(1);
	}	
}