/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:06:45 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/28 12:00:22 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

int	main(void)
{
	void	*mlx = NULL;
	// void	*mlx_win = NULL;
	void	*img = NULL;

	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "hi hi hi");
	mlx_loop(mlx);
	// (void)mlx_win;
	(void)img;
	return(0);
}