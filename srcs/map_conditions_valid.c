/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conditions_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:20:02 by jjaroens          #+#    #+#             */
/*   Updated: 2024/06/01 11:45:03 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*This file is to check the condition of the sprite in the game:
1. All sprites need to be included in the map: 1 player, 1 exit,
at least 1 collectible, at least 1 empty space, 
2. Check Wall ->Wall must be at the all the border positions e.g. square shapes
3. flood fill***/

void	ft_check_wall_border(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width - 1)
		{
			if (y == 0 || x == 0 || x == data->map_width - 1
				|| y == data->map_height - 1)
			{
				if (data->map[y][x] != '1')
				{
					ft_putstr_fd("Error: Wall need to be at border!\n", 2);
					ft_free_map(data);
					exit(EXIT_FAILURE);
				}
			}
			x++;
		}
		y++;
	}
}

void	ft_check_con_sprites(t_data *data)
{
	if (!data->empty_num || !data->collectible_num)
	{
		ft_putstr_fd("Error: Empty space or Collectible not found!\n", 2);
		ft_free_map(data);
		exit(EXIT_FAILURE);
	}
	if (data->player_num != 1 || data->exit_num != 1)
	{
		ft_putstr_fd("Error: ONLY one player and one exit allowed!\n", 2);
		ft_free_map(data);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_num_sprites(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == '0')
				data->empty_num++;
			else if (data->map[i][j] == 'C')
				data->collectible_num++;
			else if (data->map[i][j] == 'P')
			{
				data->player_num++;
				data->pos_y = i;
				data->pos_x = j;
			}
			else if (data->map[i][j] == 'E')
				data->exit_num++;
			j++;
		}
		i++;
	}
}

void	ft_check_map_size(t_data *data)
{
	if (data->map_width * data->map_height < 18)
	{
		ft_putstr_fd("Error: Map size is too small\n", 2);
		ft_free_map(data);
		exit(EXIT_FAILURE);
	}
	if (data->map_width > 38 || data->map_height > 21)
	{
		ft_putstr_fd("Error: Map size is too big\n", 2);
		ft_free_map(data);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_map_condition(t_data *data)
{
	ft_check_map_size(data);
	ft_check_character(data);
	ft_check_num_sprites(data);
	ft_check_con_sprites(data);
	ft_check_wall_border(data);
	ft_copy_map(data);
	if (!ft_check_flood_fill_map(data, data->pos_y, data->pos_x))
	{
		ft_putstr_fd("Error: the flood fill function is not successful\n", 2);
		ft_free_map_copy(data->map_copy);
		ft_free_map(data);
		exit(EXIT_FAILURE);
	}
	ft_free_map_copy(data->map_copy);
}
