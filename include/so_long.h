/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:03:28 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/06 12:09:30 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define KEY_UP_W 119
# define KEY_UP_w 87
# define KEY_DOWN_A 97
# define KEY_DOWN_a 65
# define KEY_LEFT_S 115
# define KEY_LEFT_s 85
# define KEY_RIGHT_D 100
# define KEY_RIGHT_d 68

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

///////////////////////Exit Game////////////////////////////////
void	ft_free_mlx(t_data *data);
void	ft_free_map(t_data *data);
int		ft_exit_game(t_data *data, int type);

#endif