/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:51:46 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/14 19:07:40 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int is_not_surrounded_by_walls(t_data *data, int fd)
{
	if (first_row(fd))
		return (1);
	if (last_row(data, fd))
		return (1);
	if (first_and_last_col(data, fd))
		return (1);
	return (0);
}

int wrong_shape(t_data *data, int fd)
{
    int j;
	int i;
    char *line;

    j = 0;
	lseek(fd, 0, SEEK_SET);
    while (j < data->map.height)
    {
		i = 0;
        line = get_next_line(fd);
		while (line && line[i] != '\n')
			i++;
		if (i != data->map.width)
    	{
			free(line);
        	ft_printf("The map should be a square or a rectangle\n");
        	return (1);
    	}
		free(line);
        j++;
	}
	if (is_not_surrounded_by_walls(data, fd))
		return (1);
    return (0);
}

void check_line(t_data *data, char *line)
{
	int i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == 'P')
			data->map.player++;
		if (line[i] == 'C')
			data->map.collectible++;
		if (line[i] == 'E')
			data->map.exit++;
		i++;
	}
}

void check_map(t_data *data, int fd)
{
    int j;
    char *line;

    j = 0;
	lseek(fd, 0, SEEK_SET);
    while (j < data->map.height)
    {
        line = get_next_line(fd);
        check_line(data, line);
		free(line);
        j++;
	}
	lseek(fd, 0, SEEK_SET);
}

int invalid_map(t_data *data, int fd)
{
	if (not_valid(data, fd))
		return (1);
	return (0);
}
