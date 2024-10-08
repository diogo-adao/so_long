/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:04:40 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/08 18:34:21 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data data;
	int fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		data.map.height = define_height(fd);
		data.map.width = define_width(fd);
		data.mlx_ptr = mlx_init();
		if (!data.mlx_ptr)
			return (1);
		data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.width * 48, data.map.height * 48, "Scary Maze");
		if (!data.win_ptr)
			return (free(data.mlx_ptr), 1);

		textures_init(&data);
		fill_map(&data, fd);

		mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
		mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		ft_printf("Usage: ./so_long <map>");
	return (0);
}
