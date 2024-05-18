/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:03:28 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/18 17:15:51 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define KEY_UP 65362
# define KEY_W 119
# define KEY_w 87
# define KEY_DOWN 65364
# define KEY_S 115
# define KEY_s 85
# define KEY_RIGHT 65363
# define KEY_D 100
# define KEY_d 68
# define KEY_LEFT 65361
# define KEY_A 65
# define KEY_a 97
# define IMG_SIZE 100 // to change in the code later

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
// #include "../minilibx_opengl_20191021/mlx.h"
#include <fcntl.h>

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	**map_copy;
	
	// sprites data
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*empty_space;
	
	// number of sprites
	int		wall_num;
	int		player_num;
	int		collectible_num; // delete below later
	int		empty_num;
	int		exit_num;
	
	// current position
	int		num_collect;
	int		current_x;
	int		current_y;
	int		num_moves;
	int		pos_x;
	int		pos_y;
	
	// file to map
	int		map_height;
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

//////////////////////Check map & map condition ///////////////////////////////
int		ft_check_map_ber(char const *map);
void	ft_read_file_ber(char *map, t_data *data);
void	ft_print_map(t_data *data);
void	parse_line_to_map(t_data *data, char *line);
int		check_map_width(t_data *data, char *line);
void	ft_check_map_condition(t_data *data);
void	ft_check_num_sprites(t_data *data);
void	ft_check_con_sprites(t_data *data);
int		ft_check_flood_fill_map(t_data *data, int y, int x);
void	ft_copy_map(t_data *data);
void	ft_free_map_copy(char **map);

#endif