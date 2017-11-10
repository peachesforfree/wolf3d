# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbalcort <sbalcort@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/31 11:42:23 by sbalcort          #+#    #+#              #
#    Updated: 2017/10/02 14:43:48 by sbalcort         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIBS = libs/minilibx/libmlx.a\
	   libs/libft/libft.a

SRCS = main.c color.c \
	   dda_algorithm.c \
	   mlx_key_events.c \
	   mlx_stuff.c \
	   raycasting.c \
	   declarations.c

OBJS = $(SRCS:.c=.o)

INC = .

FRAMEWORKS = -framework OpenGl -framework AppKit

all: $(NAME)
	@$(CC) $(FLAGS) -o $(NAME) $(SRCS) -I. $(LIBS) $(FRAMEWORKS)

$(NAME):
	@make -C libs/libft
	@make -C libs/minilibx

debug:
	@$(CC) -g $(FLAGS) -o $(NAME) $(SRCS) -I. $(LIBS) $(FRAMEWORKS)

clean:
	@/bin/rm -f rm $(NAME)
	@make -C libs/libft/ clean
	@make -C libs/minilibx/ clean

fclean: clean
	@/bin/rm -f rm $(NAME)
	@make -C libs/libft/ fclean
	@make -C libs/minilibx/ clean

re:fclean all
