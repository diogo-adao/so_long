/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:39:58 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/28 19:08:29 by diolivei         ###   ########.fr       */
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
	int		error;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*textures[5];
	t_map		map;
}	t_data;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

// Check map
int		invalid_map(t_data *data, char *arg);
int		first_row(char *arg);
int		last_row(t_data *data, char *arg);
int		first_and_last_col(t_data *data, char *arg);
int		wrong_shape(t_data *data, char *arg);
int		not_valid(t_data *data, char *arg);
void	check_map(t_data *data, char *arg);
int		exit_not_reachable(t_data *data, char *arg);
char	**map_copy(t_data *data, char *arg);
int		has_wrong_shape(t_data *data, char *arg);

// Filling the map
int		define_width(char *arg);
int		define_height(char *arg);
void	textures_init(t_data *data);
void	fill_map(t_data *data, char *arg);
void	put_image(t_data *data, char tile, int i, int j);
void	free_map(char **map, int height);

// Handle Moves
int		is_valid_move(t_data *data, int x, int y);
void	move_player(t_data *data, int dx, int dy);
void	move_handler(t_data *data, int new_x, int new_y);
void	move_player(t_data *data, int x, int y);

// Events
int		init_map(t_data *data);
int		on_destroy(t_data *data);
int		on_keypress(int keycode, t_data *data);

#endif
