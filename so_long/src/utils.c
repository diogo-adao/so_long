/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:43:38 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/14 19:23:57 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int first_row(int fd)
{
	int i;
	char *line;

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

char *find_last_row(t_data *data, int fd)
{
	int j;
	char *line;

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

int last_row(t_data *data, int fd)
{
	int i;
	char *line;

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

int first_and_last_col(t_data *data, int fd)
{
	int i;
	char *line;

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
