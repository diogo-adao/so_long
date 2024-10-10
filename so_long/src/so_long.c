/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:04:40 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/10 19:59:21 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void move_player(t_data *data, int x, int y)
{
    int new_x;
    int new_y;

	new_x = data->map.player_x + x;
	new_y = data->map.player_y + y;
	if (is_valid_move(data, new_x, new_y))
    {
        move_handler(data, new_x, new_y);
        data->map.map[data->map.player_y][data->map.player_x] = '0';
        data->map.map[new_y][new_x] = 'P';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0], data->map.player_x * SIZE, data->map.player_y * SIZE);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[2], new_x * SIZE, new_y * SIZE);
        data->map.player_x = new_x;
        data->map.player_y = new_y;
    }
}

char	**ft_read_map(int fd, int height)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!map)
	{
		close(fd);
		ft_printf("Error! Memory allocation failed\n");
	}
	while (i < height)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			close(fd);
			ft_printf("Error reading line\n");
		}
		i++;
	}
	map[height] = NULL;
	return (map);
}

void init_vars(t_data *data)
{
	data->map.width = 0;
	data->map.height = 0;
	data->map.exit = 0;
	data->map.player = 0;
	data->map.collectible = 0;
	data->map.map = NULL;
}

int main(int argc, char *argv[])
{
    t_data data;
    int fd;

    if (argc != 2)
    {
        ft_printf("Usage: ./so_long <map>\n");
        return (1);
    }
	init_vars(&data);
    fd = open(argv[1], O_RDONLY);
    data.map.height = define_height(fd);
    data.map.width = define_width(fd);
    if (data.map.height <= 0 || data.map.width <= 0)
    {
        ft_printf("Invalid map dimensions\n");
        close(fd);
        return (1);
    }
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
    {
        close(fd);
        return (1);
    }
    data.map.map = ft_read_map(fd, data.map.height);
    if (!data.map.map)
    {
        free(data.mlx_ptr);
        close(fd);
        return (1);
    }
    data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.width * SIZE, data.map.height * SIZE, "Scary Maze");
    if (!data.win_ptr)
    {
        free(data.map.map);
        free(data.mlx_ptr);
        close(fd);
        return (1);
    }
    textures_init(&data);
    fill_map(&data, fd);
    if (invalid_map(&data))
    {
        free(data.map.map);
        free(data.mlx_ptr);
        close(fd);
        return (1);
    }
    mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
    mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
    mlx_loop(data.mlx_ptr);
    free(data.map.map);
    free(data.mlx_ptr);
    close(fd);
    return (0);
}
