/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:19:41 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/14 19:19:54 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int not_valid(t_data *data, int fd)
{
	if (data->map.height <= 0 || data->map.width <= 0)
    {
        ft_printf("Invalid map dimensions\n");
        return (1);
    }
	if (wrong_shape(data, fd))
		return (1);
	check_map(data, fd);
	if (data->map.player != 1)
	{
		ft_printf("You can only have 1 player.\n");
		return (1);
	}
	if (data->map.exit != 1)
	{
		ft_printf("You can only have 1 exit.\n");
		return (1);
	}
	if (data->map.collectible < 1)
	{
		ft_printf("You need at least 1 collectible.\n");
		return (1);
	}
	return (0);
}
