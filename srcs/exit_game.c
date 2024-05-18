/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:30:57 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/18 21:47:46 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../minilibx-linux/mlx.h"
// #include "../libft/libft.h"
#include "../include/so_long.h"
// #include "../minilibx_opengl_20191021/mlx.h"

void	ft_free_mlx(t_data *data)
{
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
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
	// mlx_destroy_display(data->mlx); // no this function on mac
	if (data->mlx)
		free(data->mlx);
}

void	ft_free_map(t_data *data)
{
	char **tmp;
	int	i;

	tmp = data->map;
	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(tmp);
}

int	ft_exit_game(t_data *data, int	type)
{
	ft_printf("exit game\n");
	ft_printf("%i\n", type);
	ft_free_mlx(data);
	ft_free_map(data);
	return (type);
}