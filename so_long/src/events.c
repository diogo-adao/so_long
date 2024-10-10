/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:33:43 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/10 16:34:21 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	ft_printf("Game Ended");
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int on_keypress(int keycode, t_data *data)
{
    if (keycode == 65307)  // Escape key
        on_destroy(data);
    else if (keycode == 65362)  // Up arrow key
        move_player(data, 0, -1);
    else if (keycode == 65364)  // Down arrow key
        move_player(data, 0, 1);
    else if (keycode == 65361)  // Left arrow key
        move_player(data, -1, 0);
    else if (keycode == 65363)  // Right arrow key
        move_player(data, 1, 0);
    return (0);
}

