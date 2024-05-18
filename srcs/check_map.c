/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:30:19 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/18 17:25:13 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../minilibx-linux/mlx.h"
// #include "../libft/libft.h"
#include "../include/so_long.h"
//  
#include <stdio.h> // perror function

/* steps to check map
1. check if the map is .ber
2. ft_read_map if map fail need to free the map
3. Check height && width of the map
4. check if it contains all required elements "0, 1, C, E, P" (only one E & P)
5. check if it is accessible --> flood fill 
// set the mininum height and width??*/

int	ft_check_map_ber(char const *map)
{
	size_t i;
	size_t j;
	char *file;

	i = 0;
	j = 3;
	i = ft_strlen(map) - 1;
	file = ".ber";
	// ft_printf("I am ft_check_map\n");
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
	int	line_length;
	
	// ft_printf("I am check_map_width\n");
	line_length = ft_strlen(line);
	// ft_printf("line length: %i\n", line_length);
	if (!data->map_width) // initialize map width
		data->map_width = line_length;
	// ft_printf("map_width: %i\n", data->map_width);
	// this include a new line (as well?)
	// if (data->map_width != line_length) // this is contain new line
	// {
	// 	ft_printf("Error: map is not in a square shape\n");
	// 	// see if I need to free something before
	// 	exit(1);
	// }
	return (0);
}

void	parse_line_to_map(t_data *data, char *line)
{
	char	**tmp;
	int		i;
	
	// ft_printf("I am parse_line_to_map\n");
	check_map_width(data, line);
	tmp = malloc(sizeof(char *) * data->map_height + 1);
	if (!tmp)
	{
		// to write free malloc function
		ft_free_map(data);
		exit(1);
	}
	tmp[data->map_height] = (void *)0;
	i = 0;
	while (i < data->map_height - 1)
	{
		// copying old information 
		// the first info won't be in the loop
		tmp[i] = data->map[i]; // tmp copy the previous info in map
		i++;
	}
	tmp[i] = line; // init the first info for the first time and update the last line after the first looping
	if (data->map)
		free(data->map);
	data->map = tmp;
	// allocate a memory to a data height and data width
	// data height -> malloc a pointer to char pointer // malloc char pointer
}

void	ft_print_map(t_data *data)
{
	int	i;

	i = 0;
	ft_printf("The map is:\n");
	while (data->map[i])
	{
		ft_printf("%s", data->map[i]);
		i++;
	}
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
		if (!line)
			break ;
		data->map_height++;
		parse_line_to_map(data, line);
	}
	close(fd);
	if (!data->map)
	{
		ft_printf("Error: Map is empty\n");
		exit(1);
	}
	if (data->map_width * data->map_height < 16) /// To check this condition again // the smallest map that is acceptible
	{
		ft_printf("Error: Map size is too small\n");
		ft_free_map(data);
		exit(1);
	}
	// ft_print_map(data);
}

