/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:33:43 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/28 16:08:14 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	on_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (data->textures[i])
			mlx_destroy_image(data->mlx_ptr, data->textures[i]);
		i++;
	}
	free_map(data->map.map, data->map.height);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_printf("Game Ended\n");
	exit(0);
	return (0);
}

int	on_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
		on_destroy(data);
	else if (keycode == 65362 || keycode == 119)
		move_player(data, 0, -1);
	else if (keycode == 65364 || keycode == 115)
		move_player(data, 0, 1);
	else if (keycode == 65361 || keycode == 97)
		move_player(data, -1, 0);
	else if (keycode == 65363 || keycode == 100)
		move_player(data, 1, 0);
	return (0);
}

void	reinitialize_vars(t_data *data)
{
	data->map.exit = 0;
	data->map.player = 0;
	data->map.player_x = 0;
	data->map.player_y = 0;
}

int	init_map(t_data *data)
{
	reinitialize_vars(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->map.map = (char **)malloc(sizeof(char *) * (data->map.height + 1));
	if (!data->map.map)
	{
		free(data->mlx_ptr);
		return (1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map.width * SIZE,
			data->map.height * SIZE, "Scary Maze");
	if (!data->win_ptr)
	{
		free(data->map.map);
		free(data->mlx_ptr);
		return (1);
	}
	return (0);
}
