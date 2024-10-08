/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:33:43 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/08 18:33:51 by diolivei         ###   ########.fr       */
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
