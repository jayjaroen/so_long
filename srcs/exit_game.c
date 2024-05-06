/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:30:57 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/06 12:49:59 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "../include/so_long.h"
// #include "../minilibx_opengl_20191021/mlx.h"

void	ft_free_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->collectible);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->empty_space);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
}

void	ft_free_map(t_data *data)
{
	char **map;
	int	i;

	map = data->map;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_exit_game(t_data *data, int	type)
{
	ft_free_mlx(data);
	ft_free_map(data);
	return (type);
}