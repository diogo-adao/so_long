/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:04:40 by diolivei          #+#    #+#             */
/*   Updated: 2024/09/17 18:54:59 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	ft_printf("Game Ended");
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int on_keypress()
{
	static int i = -1;
	if (i == -1)
	{
		ft_printf("Game Started!\n");
		i++;
	}
	else if (i >= 0)
	{
		i++;
		ft_printf("You made %d moves\n", i);
	}
	return (0);
}

int	main(void)
{
	t_data data;
	int img_width = 256;
	int img_height = 256;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 256, 256, "hi :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	data.textures[0] = mlx_xpm_file_to_image(data.mlx_ptr, FLOOR, &img_width, &img_height);
	if (!data.textures[0])
	{
		ft_printf("Error: Failed to load XPM file: %s\n", FLOOR);
		return (free(data.win_ptr), free(data.mlx_ptr), 1);
	}

	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[0], 0, 0);

	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);

	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}
