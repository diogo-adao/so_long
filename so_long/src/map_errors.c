/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:51:46 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/28 19:08:55 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_not_surrounded_by_walls(t_data *data, char *arg)
{
	if (first_row(arg))
		return (1);
	if (last_row(data, arg))
		return (1);
	if (first_and_last_col(data, arg))
		return (1);
	return (0);
}

int	wrong_shape(t_data *data, char *arg)
{
	if (has_wrong_shape(data, arg))
		return (1);
	if (is_not_surrounded_by_walls(data, arg))
		return (1);
	return (0);
}

void	check_line(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line && line[i] != '\n')
	{
		if (line[i] == 'P')
			data->map.player++;
		if (line[i] == 'C')
			data->map.collectible++;
		if (line[i] == 'E')
			data->map.exit++;
		if (line[i] != '0' && line[i] != '1' && line[i] != 'P'
			&& line[i] != 'C' && line[i] != 'E')
			data->map.error++;
		i++;
	}
}

void	check_map(t_data *data, char *arg)
{
	int		j;
	char	*line;
	int		fd;

	j = 0;
	fd = open(arg, O_RDONLY);
	while (j < data->map.height)
	{
		line = get_next_line(fd);
		check_line(data, line);
		free(line);
		j++;
	}
	close(fd);
}

int	invalid_map(t_data *data, char *arg)
{
	if (ft_strlen(arg) < 4
		|| ft_strncmp(&arg[ft_strlen(arg) - 4], ".ber", 4) != 0)
	{
		ft_printf("The map must be a .ber file\n");
		return (1);
	}
	if (not_valid(data, arg))
		return (1);
	if (exit_not_reachable(data, arg))
	{
		ft_printf("Exit or some collectibles are not reachable");
		return (1);
	}
	if (data->map.error > 0)
	{
		ft_printf("The map can only contain '1','0','P','C','E'.");
		return (1);
	}
	return (0);
}
