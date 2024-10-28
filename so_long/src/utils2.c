/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:19:41 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/28 19:03:52 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	not_valid(t_data *data, char *arg)
{
	if (data->map.height <= 0 || data->map.width <= 0)
	{
		ft_printf("Invalid map.\n");
		return (1);
	}
	if (wrong_shape(data, arg))
		return (1);
	check_map(data, arg);
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
	if (map[cur.y][cur.x] != '0'
		&& map[cur.y][cur.x] != 'C' && map[cur.y][cur.x] != 'P')
		return ;
	map[cur.y][cur.x] = 'F';
	fill(map, size, (t_point){cur.x - 1, cur.y});
	fill(map, size, (t_point){cur.x + 1, cur.y});
	fill(map, size, (t_point){cur.x, cur.y - 1});
	fill(map, size, (t_point){cur.x, cur.y + 1});
}

void	fill_cpy(char **map, t_point size, t_point cur)
{
	if (map[cur.y][cur.x] != '0' && map[cur.y][cur.x] != 'C'
		&& map[cur.y][cur.x] != 'E' && map[cur.y][cur.x] != 'P')
		return ;
	map[cur.y][cur.x] = 'F';
	fill_cpy(map, size, (t_point){cur.x - 1, cur.y});
	fill_cpy(map, size, (t_point){cur.x + 1, cur.y});
	fill_cpy(map, size, (t_point){cur.x, cur.y - 1});
	fill_cpy(map, size, (t_point){cur.x, cur.y + 1});
}

int	fill_tmp_map(t_data *data, char **map, char **map_cpy)
{
	int	x;
	int	y;

	y = 0;
	fill(map, (t_point){data->map.width, data->map.height},
		(t_point){data->map.player_x, data->map.player_y});
	fill_cpy(map_cpy, (t_point){data->map.width, data->map.height},
		(t_point){data->map.player_x, data->map.player_y});
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (map[y][x] == 'C' || map_cpy[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	exit_not_reachable(t_data *data, char *arg)
{
	char	**tmp_map;
	char	**tmp_map_cpy;

	tmp_map = map_copy(data, arg);
	tmp_map_cpy = map_copy(data, arg);
	if (fill_tmp_map(data, tmp_map, tmp_map_cpy))
	{
		free_map(tmp_map, data->map.height);
		free_map(tmp_map_cpy, data->map.height);
		return (1);
	}
	free_map(tmp_map, data->map.height);
	free_map(tmp_map_cpy, data->map.height);
	return (0);
}
