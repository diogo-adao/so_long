/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:19:41 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/15 18:51:01 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	not_valid(t_data *data, int fd)
{
	if (data->map.height <= 0 || data->map.width <= 0)
	{
		ft_printf("Invalid map.\n");
		return (1);
	}
	if (wrong_shape(data, fd))
		return (1);
	check_map(data, fd);
	if (data->map.player != 1)
	{
		ft_printf("You can only have 1 player.\n");
		return (1);
	}
	if (data->map.exit != 1)
	{
		ft_printf("You can only have 1 exit.\n");
		return (1);
	}
	if (data->map.collectible < 1)
	{
		ft_printf("You need at least 1 collectible.\n");
		return (1);
	}
	return (0);
}

void	fill(char **map, t_point size, t_point cur)
{
	if (map[cur.y][cur.x] != '0' && map[cur.y][cur.x] != 'E'
		&& map[cur.y][cur.x] != 'C' && map[cur.y][cur.x] != 'P')
		return ;
	map[cur.y][cur.x] = 'F';
	fill(map, size, (t_point){cur.x - 1, cur.y});
	fill(map, size, (t_point){cur.x + 1, cur.y});
	fill(map, size, (t_point){cur.x, cur.y - 1});
	fill(map, size, (t_point){cur.x, cur.y + 1});
}

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

int	fill_tmp_map(t_data *data, char **map)
{
	int	x;
	int	y;

	y = 0;
	fill(map, (t_point){data->map.width, data->map.height},
		(t_point){data->map.player_x, data->map.player_y});
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (map[y][x] == 'E' || map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	exit_not_reachable(t_data *data, int fd)
{
	int		j;
	char	*line;
	char	**tmp_map;

	j = 0;
	tmp_map = (char **)malloc(sizeof(char *) * (data->map.height + 1));
	lseek(fd, 0, SEEK_SET);
	while (j < data->map.height)
	{
		line = get_next_line(fd);
		tmp_map[j] = ft_strdup(line);
		get_player_pos(data, line, j);
		free(line);
		j++;
	}
	tmp_map[j] = NULL;
	if (fill_tmp_map(data, tmp_map))
	{
		free_map(tmp_map, data->map.height);
		return (1);
	}
	free_map(tmp_map, data->map.height);
	return (0);
}
