/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:04:40 by diolivei          #+#    #+#             */
/*   Updated: 2024/09/18 18:23:06 by diolivei         ###   ########.fr       */
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
	int img_width = 48;
	int img_height = 48;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 336, 240, "Mazeland");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	data.textures[0] = mlx_xpm_file_to_image(data.mlx_ptr, FLOOR, &img_width, &img_height);
	data.textures[1] = mlx_xpm_file_to_image(data.mlx_ptr, WALL, &img_width, &img_height);
	data.textures[2] = mlx_xpm_file_to_image(data.mlx_ptr, PLAYER, &img_width, &img_height);
	data.textures[3] = mlx_xpm_file_to_image(data.mlx_ptr, COLLECT, &img_width, &img_height);
	data.textures[4] = mlx_xpm_file_to_image(data.mlx_ptr, EXIT, &img_width, &img_height);

	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 0, SIZE * 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 1, SIZE * 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 2, SIZE * 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 3, SIZE * 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 4, SIZE * 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 5, SIZE * 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 6, SIZE * 0);

	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 0, SIZE * 1);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[2], SIZE * 1, SIZE * 1);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[0], SIZE * 2, SIZE * 1);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[3], SIZE * 3, SIZE * 1);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 4, SIZE * 1);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[4], SIZE * 5, SIZE * 1);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 6, SIZE * 1);

	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 0, SIZE * 2);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[0], SIZE * 1, SIZE * 2);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 2, SIZE * 2);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 3, SIZE * 2);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[0], SIZE * 4, SIZE * 2);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[0], SIZE * 5, SIZE * 2);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 6, SIZE * 2);

	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 0, SIZE * 3);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[0], SIZE * 1, SIZE * 3);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[0], SIZE * 2, SIZE * 3);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[3], SIZE * 3, SIZE * 3);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[0], SIZE * 4, SIZE * 3);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 5, SIZE * 3);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 6, SIZE * 3);

	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 0, SIZE * 4);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 1, SIZE * 4);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 2, SIZE * 4);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 3, SIZE * 4);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 4, SIZE * 4);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 5, SIZE * 4);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], SIZE * 6, SIZE * 4);

	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);

	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}
