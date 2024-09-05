/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:04:40 by diolivei          #+#    #+#             */
/*   Updated: 2024/09/05 16:41:47 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	char *str = argv[1];
	if (argc == 2)
		ft_printf("%s", str);
	else
		ft_printf("error!");
	return (0);
}
