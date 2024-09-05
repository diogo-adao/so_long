# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 19:25:13 by diolivei          #+#    #+#              #
#    Updated: 2024/09/05 16:57:48 by diolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I/usr/include -Ilibs/mlx -Ilibs/libft
MLX = libs/mlx/libmlx.a
MLX_FLAGS = -Llibs/mlx -lmlx -L/usr/lib/X11 -lXext -lX11
LIBFT = libs/libft/libft.a
LIBFT_FLAGS = -Llibs/libft -lft

SRCS = $(wildcard src/*.c)
NAME = so_long

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $(SRCS) $(INCLUDES) $(LIBFT) $(MLX_FLAGS) $(LIBFT_FLAGS)

$(LIBFT):
	make -C libs/libft

$(MLX):
	@if [ ! -d "libs/mlx" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git libs/mlx; \
	fi
	make -C libs/mlx

clean:
	make -C libs/libft clean
	make -C libs/mlx clean

fclean: clean
	rm -f $(NAME)
	make -C libs/libft fclean

re: fclean all

.PHONY: all clean fclean re
