/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:03:28 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/07 22:43:09 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
// # define KEY_UP 65362
// # define KEY_W 119
// # define KEY_w 87
// # define KEY_DOWN 65364
// # define KEY_S 115
// # define KEY_s 85
// # define KEY_RIGHT 65363
// # define KEY_D 100
// # define KEY_d 68
// # define KEY_LEFT 65361
// # define KEY_A 65
// # define KEY_a 97
//////////// MAC /////
# define KEY_W 3
# define KEY_A 0
# define KEY_S 2
# define KEY_D 2
# define ESC 53
# define IMG_SIZE 100 // to change in the code later

// # include "../minilibx-linux/mlx.h"
#include "../minilibx_opengl_20191021/mlx.h"
#include <fcntl.h>

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

	// file to map
	int		map_heigth;
	int		map_width;
	
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

//////////////////////Check map ///////////////////////////////
int	ft_check_map_ber(char const *map);

#endif