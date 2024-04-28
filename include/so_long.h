/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:03:28 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/28 16:18:55 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	// to add size, width
}	t_data;