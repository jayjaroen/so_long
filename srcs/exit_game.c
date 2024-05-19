/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:30:57 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/19 16:59:31 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_mlx(t_data *data)
{
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->collectible)
		mlx_destroy_image(data->mlx, data->collectible);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->empty_space)
		mlx_destroy_image(data->mlx, data->empty_space);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
}

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

int	ft_exit_game(t_data *data)
{
	ft_free_mlx(data);
	ft_free_map(data);
	exit(0);
}

// mlx_destroy_display(data->mlx); // no this function on mac
// if (data->mlx)
// 	free(data->mlx);