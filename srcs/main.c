/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:06:45 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/19 16:04:47 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Wrong argument\n", 2);
		exit (EXIT_FAILURE);
	}
	if (ft_check_map_ber(argv[1]))
	{
		ft_putstr_fd("Wrong argument: Check file\n", 2);
		exit (EXIT_FAILURE);
	}
	ft_bzero(&data, sizeof(t_data));
	ft_read_file_ber(argv[1], &data);
	ft_check_map_condition(&data);
	data.mlx = mlx_init();
	ft_set_image(&data);
	data.mlx_win = mlx_new_window(data.mlx, data.map_width * IMG_SIZE,
			data.map_height * IMG_SIZE, "Save Panda!");
	ft_render_image(&data);
	ft_make_move(&data);
	mlx_loop(data.mlx);
	return (0);
}
