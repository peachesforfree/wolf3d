# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbalcort <sbalcort@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/31 11:42:23 by sbalcort          #+#    #+#              #
#    Updated: 2017/11/10 11:58:06 by gaguirre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CFLAGS = -Wall -Wextra -Werror -g

SRC_FILES = main.c declarations.c dda_algorithm.c \
						color.c mlx_key_events.c mlx_stuff.c \
						raycasting.c

OBJ_FILES = $(SRC_FILES:.c=.o)

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./incl/
MLX_DIR = ./libs/minilibx/
LIBFT_DIR = ./libs/libft/

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
MLX = $(addprefix $(MLX_DIR), libmlx.a)
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

LINK = -L $(MLX_DIR) -L $(LIBFT_DIR) \
				-lmlx -lft -framework OpenGL -framework AppKit

all: obj $(LIBFT) $(MLX) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(CFLAGS) -I $(MLX_DIR) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

$(NAME): $(OBJ)
	@gcc $(OBJ) $(LINK) -lm -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all re
