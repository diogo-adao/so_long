/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:39:58 by diolivei          #+#    #+#             */
/*   Updated: 2024/09/18 17:26:17 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define SIZE 48
# define FLOOR "textures/floor.xpm"
# define WALL "textures/wall.xpm"
# define PLAYER "textures/ghost.xpm"
# define COLLECT "textures/pumpkin.xpm"
# define EXIT "textures/exit.xpm"

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		player;
	int		collectible;
	int		exit;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	t_map		map;
}	t_data;

#endif
