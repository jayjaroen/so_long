/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:03:28 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/04 17:32:56 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
// #include "../minilibx_opengl_20191021/mlx.h"

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

	// current position
	int		num_collect;
	int		current_x;
	int		current_y;
	int		num_moves;
}	t_data;

////////////////////////// Image Handling //////////////////////
void	ft_set_image(t_data *data);
void	ft_render_image(t_data *data);
void	ft_to_render(t_data *data, int y, int x);


/////////////////////////move player////////////////////////////
void	ft_move_player(int x, int y, t_data *data);
int		ft_check_key_input(int key, t_data *data);
void	ft_make_move(t_data *data);

#endif