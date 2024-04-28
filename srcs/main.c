/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:06:45 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/28 16:13:11 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "../include/so_long.h"

// main function check the agrument if the argument is valid
// check if the map is valide
// .ber function
int	main(void)
{
	// void	*mlx = NULL;
	// void	*mlx_win = NULL;
	// void	*img = NULL;
	t_data	data;
	char	*test;
	int	i;
	
	ft_bzero(&data, sizeof(t_data));
	test = "1111111111111\n10010000000C1\n1000011111001\n1P0011E000001\n1111111111111\n";
	data.map = ft_split(test, '\n');
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1920, 1080, "hi hi hi");
	i = 0;
	while (data.map[i])
	{
		ft_printf("%s\n", data.map[i]);
		i++;
	}
	// mlx xpm file to image
	// mlx image to window
	// mlx = mlx_init();
	// // img = mlx_new_image(mlx, 1920, 1080);
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "hi hi hi");
	mlx_loop(data.mlx);
	(void)data.mlx_win;
	// (void)img;
	return(0);
	// image 64* 64 pixel 
}