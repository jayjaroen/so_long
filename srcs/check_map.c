/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:30:19 by jjaroens          #+#    #+#             */
/*   Updated: 2024/06/01 14:47:48 by jjaroens         ###   ########.fr       */
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
	size_t	i;
	size_t	j;
	char	*file;

	j = 3;
	i = ft_strlen(map) - 1;
	file = ".ber";
	while (j && file[j] == map[i])
	{
		j--;
		i--;
	}
	if (j == 0 & file[j] != map[i])
		return (1);
	else
		return (0);
}

int	check_map_width(t_data *data, char *line)
{
	int	line_length;

	line_length = ft_strlen(line);
	if (!data->map_width)
		data->map_width = line_length;
	if (data->map_width != line_length)
	{
		ft_putstr_fd("Error: Map is not rectangle shape!", 2);
		ft_free_map(data);
		exit(EXIT_FAILURE);
	}
	return (0);
}

static void	parse_line_to_map(t_data *data, char *line, int fd)
{
	char	**tmp;
	int		i;

	check_map_width(data, line);
	tmp = malloc(sizeof(char *) * (data->map_height + 1));
	if (!tmp)
	{
		close(fd);
		ft_free_map(data);
		exit(EXIT_FAILURE);
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
		perror("Error: opening the file\n");
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
		parse_line_to_map(data, line, fd);
	}
	close(fd);
	if (!data->map)
	{
		ft_putstr_fd("Error: Map is empty\n", 2);
		exit (EXIT_FAILURE);
	}
}
