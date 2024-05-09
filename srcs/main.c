/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:06:45 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/07 22:11:03 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "../include/so_long.h"
#include "../minilibx_opengl_20191021/mlx.h"

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

int	main(void)
{
	t_data	data;
	char	*test;
	int	i;
	
	// if (argc != 2)
	// {
	// 	ft_printf("Wrong argument\n");
	// 	return (1);
	// }
	// if (ft_check_map_ber(argv[1]))
	// {
	// 	ft_printf("back in main but wrong argument\n");
	// 	exit (1);
	// }
	ft_bzero(&data, sizeof(t_data));
	test = "1111111111111\n10010000000C1\n1000011111001\n1P0011E000001\n1111111111111\n";
	data.map = ft_split(test, '\n');
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1300, 500, "Save Panda!");
	i = 0;
	while (data.map[i])
	{
		ft_printf("%s\n", data.map[i]);
		i++;
	}
	ft_set_image(&data);
	ft_render_image(&data);
	ft_make_move(&data);
	mlx_loop(data.mlx);
	// (void)data.mlx_win;
	return(0);
}