/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:30:19 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/07 22:11:31 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "../include/so_long.h"
#include "../minilibx_opengl_20191021/mlx.h"

/* steps to check map
1. check if the map is .ber
2. ft_read_map if map fail need to free the map
3. Check height && width of the map
4. check if it contains all required elements "0, 1, C, E, P" (only one E & P)
5. check if it is accessible --> flood fill */

int	ft_check_map_ber(char const *map)
{
	size_t i;
	size_t j;
	char *file;

	i = 0;
	j = 3;
	i = ft_strlen(map) - 1;
	file = ".ber";
	ft_printf("I am ft_check_map\n");
	if (!map)
		return (1);
	while (j && file[j] == map[i])
	{
		j--;
		i++;
		return (0);
	}
	return (1);
}

// void	ft_read_file_ber(char const *map, t_data *data)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open(map, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening the file\n");
// 		exit(EXIT_FAILURE);
// 	}
	
// }

