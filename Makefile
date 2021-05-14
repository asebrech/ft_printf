# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asebrech <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 16:13:10 by asebrech          #+#    #+#              #
#    Updated: 2021/05/14 13:14:01 by asebrech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = include
DLIB = libft
PLIB = libft/libft.a
NAME = libftprintf.a
SRC = srcs/ft_printf.c \
	srcs/ft_printf_utiles.c \
	srcs/ft_sort.c \
	srcs/ft_parsing.c \
	srcs/ft_convert_char.c \
	srcs/ft_convert_nbr00.c \
	srcs/ft_convert_nbr01.c \
	srcs/ft_convert_str.c
OBJ = $(SRC:.c=.o)
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(DLIB) bonus
	cp $(PLIB) $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	make -C $(DLIB) clean
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(PLIB)
	$(RM) $(NAME)

re : fclean all

.c.o :
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)

.PHONY : all clean fclean re
