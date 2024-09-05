# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 19:25:13 by diolivei          #+#    #+#              #
#    Updated: 2024/09/05 17:41:24 by diolivei         ###   ########.fr        #
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

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
BOLD_GREEN = \033[1;32m
NO_COLOR	=	\033[0m

all: $(NAME)
	@sleep 1
	@echo "\n✅ $(BOLD_GREEN)Game is ready to play!\n$(NO_COLOR)"
	@echo "  /\_/\  (\n ( ^.^ ) _)\n   \\\"/  (\n ( | | )\n(__d b__)\n"

$(NAME): $(SRCS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -o $@ $(SRCS) $(INCLUDES) $(LIBFT) $(MLX_FLAGS) $(LIBFT_FLAGS)

$(LIBFT):
	@make -C libs/libft > /dev/null 2>&1
	@echo "\n📚 $(BOLD_PURPLE)Libft compiled.$(NO_COLOR)\n"

$(MLX):
	@if [ ! -d "libs/mlx" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git libs/mlx; \
	fi
	@make -C libs/mlx > /dev/null 2>&1
	@echo "\n🎮 $(BOLD_CYAN)Minilibx compiled.$(NO_COLOR)\n"

clean:
	@make -C libs/libft clean > /dev/null 2>&1
	@make -C libs/mlx clean > /dev/null 2>&1
	@echo "\n🧹 $(BOLD_YELLOW)Project cleaned.$(NO_COLOR)\n"

fclean: clean
	@rm -f $(NAME)
	@make -C libs/libft fclean > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re
