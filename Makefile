# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 15:58:39 by nmorandi          #+#    #+#              #
#    Updated: 2023/02/01 15:33:49 by nmorandi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
CC=cc
CCFLAGS=-Wall -Werror -Wextra
FILES=so_long.c				\
	map_converter.c			\
	make_map.c				\
	check_map.c				\
	player.c				\
	render.c				\
	utils.c					\
	queue.c					\
	pathfinder.c			\
	path_utils.c			\

OBJ=$(FILES:.c=.o)

ifdef BONUS
	FILES=bonus/so_long_bonus.c	\
	map_converter.c				\
	make_map.c					\
	check_map.c					\
	player.c					\
	bonus/render_bonus.c		\
	utils.c						\
	queue.c						\
	pathfinder.c				\
	path_utils.c				\

endif

%.o : %.c
	$(CC) $(CCFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

all: submake $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -L ./libft -lft -L ./libft/ft_printf -lftprintf -o $(NAME)

bonus:
	make BONUS=1;

submake:
	(cd ./libft; make all)
	(cd ./libft/ft_printf; make all)
	(cd ./mlx_linux; make all)

subclean:
	(cd ./libft; make clean)
	(cd ./libft/ft_printf; make clean)
	(cd ./mlx_linux; make clean)

subfclean:
	(cd ./libft; make fclean)
	(cd ./libft/ft_printf; make fclean)

clean: subclean
	rm -f $(OBJ)
	(cd bonus; rm -rf render_bonus.o)
	(cd bonus; rm -rf so_long_bonus.o)

fclean: clean subfclean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean bonus
