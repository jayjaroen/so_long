/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:06:45 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/18 22:00:43 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../minilibx-linux/mlx.h"
// #include "../libft/libft.h"
#include "../include/so_long.h"
// #include "../minilibx_opengl_20191021/mlx.h"

// main function check the agrument if the argument is valid
// check if the map is valide
// .ber function
/* Steps 
1. Create control function - moving the characters
2. Setting conditions to end the game --> know how many collectibles
to collect && moving the players
3. Data structure && update the player move
4. Error prevention -> checking the player map
5. Get next line to read map
6. Understand mlx function (e.g. the arguments & input)*/

int	main(int argc, char **argv)
{
	t_data	data;
		
	if (argc != 2)
	{
		ft_printf("Wrong argument\n");
		return (1);
	}
	if (ft_check_map_ber(argv[1]))
	{
		ft_printf("back in main but wrong argument\n");
		exit (1);
	}
	ft_bzero(&data, sizeof(t_data));
	ft_read_file_ber(argv[1], &data);
	ft_check_map_condition(&data);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1300, 500, "Save Panda!");
	ft_set_image(&data);
	ft_render_image(&data);
	ft_make_move(&data);
	mlx_loop(data.mlx);
	(void)data.mlx_win;
	return(0);
}