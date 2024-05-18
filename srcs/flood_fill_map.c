/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:03:08 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/18 22:30:23 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_map_copy(char **map)
{
	char	**tmp;
	int		i;
	
	tmp = map;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(tmp);
}

void	ft_copy_map(t_data *data)
{
	char 	**copy;
	int		i;
	
	copy = ft_calloc(data->map_height + 1, sizeof(char *));
	if (!copy)
	{
		ft_free_map(data);
		exit(1);
	}	
	i = 0;
	while (i < data->map_height)
	{
		copy[i] = ft_strdup(data->map[i]);
		if (copy[i] == NULL)
		{
			ft_free_map_copy(copy);
			exit(1);
		}
		i++;
	}
	data->map_copy = copy;
}

void	ft_check_character(t_data *data)
{
	int	y;
	int x;

	y = 0;
	ft_printf("I am at ft_check_character\n");
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] != '0' && data->map[y][x] != '1' 
			&& data->map[y][x] != 'P' && data->map[y][x] != 'E'
			&& data->map[y][x] != 'C' && data->map[y][x] != '\n')
			{
				perror("Map Input Error! Check Character!\n");
				ft_free_map(data);
				exit(1);
			}
			x++;			
		}
		y++;
	}
}

int	ft_check_flood_fill_map(t_data *data, int y, int x)
{
	static int	collectible; // retain value between function call?
	static int	exit; // 0 at the begining

	ft_printf("/////////I am at ft_check_flood_fill_map//////////////////\n");
	if (data->map_copy[y][x] == '1')
		return (0);
	if (data->map_copy[y][x] == 'C')
		collectible++;
	if (data->map_copy[y][x] == 'E')
		exit++;
	ft_printf("before changing to wall\n");
	ft_printf("the pos is %c\n", data->map_copy[y][x]);
	data->map_copy[y][x] = '1';
	ft_check_flood_fill_map(data, y + 1, x);
	ft_check_flood_fill_map(data, y - 1, x);
	ft_check_flood_fill_map(data, y, x + 1);
	ft_check_flood_fill_map(data, y, x - 1);
	ft_printf("total collectible: %i\n", data->collectible_num);
	ft_printf("current collectible: %i\n", collectible);
	ft_printf("current exit: %i\n", exit);
	if (data->collectible_num == collectible && exit == 1)
		return (1);
	return (0);
}