/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:30:19 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/10 22:54:03 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "../include/so_long.h"
#include "../minilibx_opengl_20191021/mlx.h"
#include <stdio.h> // perror function

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

int	check_map_width(t_data *data, char *line)
{
	size_t	line_length;
	
	line_length = ft_strlen(line);
	if (!data->map_width) // initialize map width
		data->map_width = line_length;
	if (data->map_width != line_length)
	{
		ft_printf("Error: map is not in a square shape\n");
		// see if I need to free something before
		exit(1);
	}
	return (0);
}

int	parse_line_to_map(t_data *data, char *line)
{
	char	*tmp;
	
	if (!line)
		return (0);
	check_map_width(data, line);
	data->map_heigth++;
	tmp = malloc(sizeof(char **) * data->map_heigth + 1);
	if (!tmp)
	{
		// to write free malloc function
		// ft_free_line_to_map
		exit(1);
	}
	// allocate a memory to a data height and data width
	// data height -> malloc a pointer to char pointer // malloc char pointer
}

void	ft_read_file_ber(char *map, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening the file\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line = get_next_line(fd);	
	}
}

