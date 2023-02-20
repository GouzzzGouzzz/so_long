# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 15:58:39 by nmorandi          #+#    #+#              #
#    Updated: 2023/01/20 22:46:17 by gouz             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=cc
CCFLAGS=-Wall -Werror -Wextra
FILES=ft_printf.c		\
	ft_get_flag.c		\
	ft_print_hexa.c		\
	ft_print_unsigned.c	\
	ft_print_integer.c	\
	ft_putchar.c		\
	ft_putstr.c			\
	ft_print_address.c	\
	ft_print_arr_rev.c	\

OBJ=$(FILES:.c=.o)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(NAME)

$(NAME):
	$(CC) -c $(FILES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
