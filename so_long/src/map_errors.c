/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:51:46 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/10 18:52:51 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int wrong_shape(t_data *data)
{
    int i;
    int j;
    int line_length;

    i = 0;
    while (i < data->map.height)
    {
        j = 0;
        line_length = 0;
        while (data->map.map[i][j] && data->map.map[i][j] != '\n')
        {
            line_length++;
            j++;
        }
        if (line_length != data->map.width)
        {
            ft_printf("The map should be a square or a rectangle\n");
            return (1);
        }
        i++;
    }
    return (0);
}


int invalid_map(t_data *data)
{
	if (wrong_shape(data))
		return (1);
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
