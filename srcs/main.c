/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:06:45 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/28 14:50:47 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"

int	main(void)
{
	void	*mlx = NULL;
	void	*mlx_win = NULL;
	void	*img = NULL;

	ft_printf("hi there!\n");
	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "hi hi hi");
	mlx_loop(mlx);
	(void)mlx_win;
	(void)img;
	return(0);
	// image 64* 64 pixel 
}