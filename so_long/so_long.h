/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:39:58 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/10 19:48:48 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/libft/libft.h"
# include "libs/mlx/mlx.h"
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
	int		player_x;
	int		player_y;
	int		collectible;
	int		exit;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*textures[5];
	t_map		map;
}	t_data;

// Filling the map
int define_width(int fd);
int define_height(int fd);
void textures_init(t_data *data);
void fill_map(t_data *data, int fd);
void move_player(t_data *data, int dx, int dy);
int is_valid_move(t_data *data, int x, int y);
void move_handler(t_data *data, int new_x, int new_y);
int invalid_map(t_data *data);

// Events
int on_destroy(t_data *data);
int on_keypress(int keycode, t_data *data);

#endif
