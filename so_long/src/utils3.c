/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:08:41 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/28 19:09:30 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_player_pos(t_data *data, char *line, int j)
{
	int	i;

	i = 0;
	if (line)
	{
		while (line[i] && line[i] != '\n')
		{
			if (line[i] == 'P')
			{
				data->map.player_x = i;
				data->map.player_y = j;
			}
			i++;
		}
	}
}

char	**map_copy(t_data *data, char *arg)
{
	int		j;
	int		fd;
	char	*line;
	char	**tmp_map;

	tmp_map = (char **)malloc(sizeof(char *) * (data->map.height + 1));
	fd = open(arg, O_RDONLY);
	j = 0;
	while (j < data->map.height)
	{
		line = get_next_line(fd);
		tmp_map[j] = ft_strdup(line);
		get_player_pos(data, line, j);
		free(line);
		j++;
	}
	tmp_map[j] = NULL;
	close(fd);
	return (tmp_map);
}

int	has_wrong_shape(t_data *data, char *arg)
{
	int		j;
	int		i;
	char	*line;
	int		fd;

	j = 0;
	fd = open(arg, O_RDONLY);
	while (j < data->map.height)
	{
		i = 0;
		line = get_next_line(fd);
		while (line && line[i] != '\n')
			i++;
		if (i != data->map.width)
		{
			free(line);
			close(fd);
			ft_printf("The map should be a square or a rectangle\n");
			return (1);
		}
		free(line);
		j++;
	}
	close(fd);
	return (0);
}
