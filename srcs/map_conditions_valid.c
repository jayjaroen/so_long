/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conditions_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:20:02 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/11 17:38:39 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "../include/so_long.h"
// #include "../minilibx_opengl_20191021/mlx.h"

/*This file is to check the condition of the sprite in the game:
1. All sprites need to be included in the map: 1 player, 1 exit,
at least 1 collectible, at least 1 empty space, at least 16 wall
2. Check Wall ->Wall must be at the all the border positions e.g. square shapes
3. flood fill***/

void	ft_check_wall_border(t_data *data)
{
	ft_printf("I am at check wall border\n");
	char	**tmp;
	int		y;
	int		x;
	
	y = 0;
	tmp = data->map;
	ft_printf("map height: %i\n", data->map_height);
	ft_printf("map width: %i\n", data->map_width);
	while (y < data->map_height - 1)
	{
		x = 0;
		while (x < data->map_width - 1)
		{
			if ( y == 0 || x == 0 || x == data->map_width - 1 
				|| y == data->map_height - 1)
			{
				if (tmp[y][x] != '1')
				{
					ft_printf("the position is %c\n", tmp[y][x]);
					ft_printf("the current pos of y is %i, the current pos of x is %i\n", y, x);
					ft_printf("Wall need to be at border!\n");
					ft_free_map(data);
					exit(1);
				}
			}
			x++;
		}
		y++;
	}
	ft_printf("Wall is at border!\n");
}

void	ft_check_con_sprites(t_data *data)
{
	ft_printf("I am at ft_check_con_sprites\n");
	if (data->wall_num < 16)
	{
		ft_printf("Wall is not met the condition\n");// can use perror?
		ft_free_map(data);
		exit(1);
	}
	if (!data->empty_num || !data->collectible_num)
	{
		ft_printf("Empty space or Collectible not found!\n");
		ft_free_map(data);
		exit(1);
	}
	if (data->player_num != 1 || data->exit_num != 1)
	{
		ft_printf("Wrong Format! One player and one exit allowed!\n");
		ft_free_map(data);
		exit(1);
	}
}

void	ft_check_num_sprites(t_data *data)
{
	char	**tmp;
	int		i;
	int		j;

	ft_printf("I am at ft_check_num_sprites\n");
	tmp = data->map;
	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (tmp[i][j] == '1')
				data->wall_num++;
			else if (tmp[i][j] == '0')
				data->empty_num++;
			else if (tmp[i][j] == 'C')
				data->collectible_num++;
			else if (tmp[i][j] == 'P')
				data->player_num++;
			else if (tmp[i][j] == 'E')
				data->exit_num++;
			j++;
		}
		i++;
	}
}

void	ft_check_map_condition(t_data *data)
{
	ft_printf("I am at ft_check_map_condition\n");
	ft_check_num_sprites(data);
	ft_printf("The number of Wall:%i\n", data->wall_num);
	ft_printf("The number of player: %i\n", data->player_num);
	ft_printf("The number of exit:%i\n", data->exit_num);
	ft_printf("The number of collectible:%i\n", data->collectible_num);
	ft_printf("The number of empty space: %i\n", data->empty_num);
	ft_check_con_sprites(data);
	ft_check_wall_border(data);	
}