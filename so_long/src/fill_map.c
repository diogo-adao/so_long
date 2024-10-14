/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:59:18 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/14 17:05:42 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

	size = SIZE;
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
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[1], i * SIZE, j * SIZE);
		if (line[i] == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0], i * SIZE, j * SIZE);
		if (line[i] == 'P')
		{
			data->map.player_x = i;
			data->map.player_y = j;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[2], i * SIZE, j * SIZE);
		}
		if (line[i] == 'C')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[3], i * SIZE, j * SIZE);
		if (line[i] == 'E')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[4], i * SIZE, j * SIZE);
		i++;
	}
}
void fill_map(t_data *data, int fd)
{
    int j;
    char *line;

    j = 0;
	lseek(fd, 0, SEEK_SET);
    while (j < data->map.height)
    {
        line = get_next_line(fd);
        data->map.map[j] = ft_strdup(line);
        free(line);
        fill_line(data, data->map.map[j], j);
        j++;
	}
	lseek(fd, 0, SEEK_SET);
}


