/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:04:40 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/14 19:20:10 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void init_vars(t_data *data)
{
	data->map.exit = 0;
	data->map.player = 0;
	data->map.collectible = 0;
}

void free_map(char **map, int height)
{
    for (int i = 0; i < height; i++)
    {
        free(map[i]);
    }
    free(map);
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
    fd = open(argv[1], O_RDONLY);
    data.map.height = define_height(fd);
    data.map.width = define_width(fd);
	init_vars(&data);
	if (invalid_map(&data, fd))
    {
        close(fd);
        return (1);
    }
	init_map(&data, fd);
    textures_init(&data);
    fill_map(&data, fd);
    mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
    mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
    mlx_loop(data.mlx_ptr);
    close(fd);
    return (0);
}
