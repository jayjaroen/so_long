/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:03:28 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/01 20:44:24 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include "../minilibx-linux/mlx.h"
#include "../minilibx_opengl_20191021/mlx.h"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	// to add size, width
	
	// sprites data
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*empty_space;
}	t_data;

////////////////////////// Image Handling //////////////////////
void	ft_set_image(t_data *data);
void	ft_render_image(t_data *data);
void	ft_to_render(t_data *data, int y, int x);

#endif