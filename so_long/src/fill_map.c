/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:59:18 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/30 15:46:49 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	define_width(char *arg)
{
	char	*line;
	int		width;
	int		fd;

	width = 0;
	fd = open(arg, O_RDONLY);
	line = get_next_line(fd);
	if (line)
	{
		while (line[width] != '\n' && line[width] != '\0')
			width++;
		free(line);
	}
	close(fd);
	return (width);
}

int	define_height(char *arg)
{
	char	*line;
	int		height;
	int		fd;

	height = 0;
	fd = open(arg, O_RDONLY);
	line = get_next_line(fd);
	while (line && line[0] != '\n')
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	close(fd);
	return (height);
}

void	textures_init(t_data *data)
{
	int	size;

	size = SIZE;
	data->textures[0]
		= mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, &size, &size);
	data->textures[1]
		= mlx_xpm_file_to_image(data->mlx_ptr, WALL, &size, &size);
	data->textures[2]
		= mlx_xpm_file_to_image(data->mlx_ptr, PLAYER, &size, &size);
	data->textures[3]
		= mlx_xpm_file_to_image(data->mlx_ptr, COLLECT, &size, &size);
	data->textures[4]
		= mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &size, &size);
}

void	fill_line(t_data *data, char *line, int j)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		put_image(data, line[i], i, j);
		i++;
	}
}

void	fill_map(t_data *data, char *arg)
{
	int		j;
	char	*line;
	int		fd;

	j = 0;
	fd = open(arg, O_RDONLY);
	while (j < data->map.height)
	{
		line = get_next_line(fd);
		data->map.map[j] = ft_strdup(line);
		free(line);
		fill_line(data, data->map.map[j], j);
		j++;
	}
	data->map.map[j] = NULL;
	close(fd);
}
