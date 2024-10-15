/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:43:38 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/15 18:48:35 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	first_row(int fd)
{
	int		i;
	char	*line;

	i = 0;
	lseek(fd, 0, SEEK_SET);
	line = get_next_line(fd);
	if (line)
	{
		while (line[i] && line[i] != '\n')
		{
			if (line[i] != '1')
			{
				free(line);
				ft_printf("The map must be surrounded by walls.");
				return (1);
			}
			i++;
		}
		free(line);
	}
	return (0);
}

char	*find_last_row(t_data *data, int fd)
{
	int		j;
	char	*line;

	j = 0;
	lseek(fd, 0, SEEK_SET);
	while (j < data->map.height)
	{
		line = get_next_line(fd);
		j++;
		if (j < data->map.height)
			free(line);
	}
	return (line);
}

int	last_row(t_data *data, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = find_last_row(data, fd);
	if (line)
	{
		while (line[i] && line[i] != '\n')
		{
			if (line[i] != '1')
			{
				free(line);
				ft_printf("The map must be surrounded by walls.");
				return (1);
			}
			i++;
		}
		free(line);
	}
	return (0);
}

int	first_and_last_col(t_data *data, int fd)
{
	int		i;
	char	*line;

	i = 0;
	lseek(fd, 0, SEEK_SET);
	while (i < data->map.height)
	{
		line = get_next_line(fd);
		if (line)
		{
			if (line[0] != '1' || line[data->map.width - 1] != '1')
			{
				free(line);
				ft_printf("The map should be surrounded by walls.");
				return (1);
			}
			free(line);
		}
		i++;
	}
	return (0);
}

void	put_image(t_data *data, char tile, int i, int j)
{
	int	texture_index;

	if (tile == '1')
		texture_index = 1;
	else if (tile == '0')
		texture_index = 0;
	else if (tile == 'P')
		texture_index = 2;
	else if (tile == 'C')
		texture_index = 3;
	else if (tile == 'E')
		texture_index = 4;
	else
		return ;
	if (tile == 'P')
	{
		data->map.player_x = i;
		data->map.player_y = j;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->textures[texture_index], i * SIZE, j * SIZE);
}
