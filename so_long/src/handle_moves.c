/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:37:44 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/15 18:39:16 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_valid_move(t_data *data, int x, int y)
{
	if (data->map.map[y][x] == '1')
	{
		ft_printf("You can't move into a wall!\n");
		return (0);
	}
	if (data->map.map[y][x] == 'E' && data->map.collectible != 0)
	{
		ft_printf("You can't leave without catching all collectibles\n");
		return (0);
	}
	return (1);
}

void	move_handler(t_data *data, int new_x, int new_y)
{
	static int	i;

	i++;
	if (data->map.map[new_y][new_x] == 'C')
	{
		data->map.collectible--;
		ft_printf("Collectible found! %d remaining.\n", data->map.collectible);
	}
	if (data->map.map[new_y][new_x] == 'E' && data->map.collectible == 0)
	{
		ft_printf("You made %d moves\n", i);
		ft_printf("You win!\n");
		on_destroy(data);
	}
	else
		ft_printf("You made %d moves\n", i);
}

void	move_player(t_data *data, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = data->map.player_x + x;
	new_y = data->map.player_y + y;
	if (is_valid_move(data, new_x, new_y))
	{
		move_handler(data, new_x, new_y);
		data->map.map[data->map.player_y][data->map.player_x] = '0';
		data->map.map[new_y][new_x] = 'P';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0],
			data->map.player_x * SIZE, data->map.player_y * SIZE);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->textures[2], new_x * SIZE, new_y * SIZE);
		data->map.player_x = new_x;
		data->map.player_y = new_y;
	}
}
