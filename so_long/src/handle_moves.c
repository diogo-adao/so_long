/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:37:44 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/10 17:55:48 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int is_valid_move(t_data *data, int x, int y)
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

void move_handler(t_data *data, int new_x, int new_y)
{
	static int i;

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
