/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:59:18 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/08 18:31:32 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int define_width(int fd)
{
	char *line;
	int width;

	width = 0;
	lseek(fd, 0, SEEK_SET);
	line = get_next_line(fd);
	if (line)
	{
		while (line[width] != '\n' && line[width] != '\0')
			width++;
		free(line);
	}
	lseek(fd, 0, SEEK_SET);
	return (width);
}

int define_height(int fd)
{
	char *line;
	int height;

	height = 0;
	lseek(fd, 0, SEEK_SET);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	lseek(fd, 0, SEEK_SET);
	return (height);
}

void textures_init(t_data *data)
{
	int size;

	size = 48;
	data->textures[0] = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, &size, &size);
	data->textures[1] = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &size, &size);
	data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER, &size, &size);
	data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr, COLLECT, &size, &size);
	data->textures[4] = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &size, &size);
}

void fill_line(t_data *data, char *line, int j)
{
	int i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == '1')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[1], i * 48, j * 48);
		if (line[i] == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0], i * 48, j * 48);
		if (line[i] == 'P')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[2], i * 48, j * 48);
		if (line[i] == 'C')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[3], i * 48, j * 48);
		if (line[i] == 'E')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[4], i * 48, j * 48);
		i++;
	}
}

void fill_map(t_data *data, int fd)
{
	int j;
	int height;
	char *line;

	j = 0;
	height = define_height(fd);
	while (j < height)
	{
		line = get_next_line(fd);
		fill_line(data, line, j);
		free(line);
		j++;
	}
}
