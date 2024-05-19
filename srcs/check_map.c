/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:30:19 by jjaroens          #+#    #+#             */
/*   Updated: 2024/05/19 12:23:23 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

	j = 3;
	i = ft_strlen(map) - 1;
	file = ".ber";
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
	
	line_length = ft_strlen(line);
	if (!data->map_width)
		data->map_width = line_length;
	if (data->map_width != line_length)
	{
		ft_printf("Map is not rectangle shape!");
		ft_free_map(data);
		exit(1);
	}
	return (0);
}

void	parse_line_to_map(t_data *data, char *line)
{
	char	**tmp;
	int		i;
	
	check_map_width(data, line);
	tmp = malloc(sizeof(char *) * (data->map_height + 1));
	if (!tmp)
	{
		ft_free_map(data);
		exit(1);
	}
	tmp[data->map_height] = (void *)0;
	i = 0;
	while (i < data->map_height - 1)
	{
		tmp[i] = data->map[i];
		i++;
	}
	tmp[i] = line;
	if (data->map)
		free(data->map);
	data->map = tmp;
}

void	ft_print_map(t_data *data)
{
	int	i;

	i = 0;
	ft_printf("The map is:\n");
	while (data->map[i])
	{
		ft_printf("%s\n", data->map[i]);
		i++;
	}
	ft_printf("height is: %i\n", data->map_height);
	ft_printf("width is: %i\n", data->map_width);
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
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
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

