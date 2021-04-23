# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asebrech <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 16:13:10 by asebrech          #+#    #+#              #
#    Updated: 2021/04/23 18:22:44 by asebrech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = libft.a
NAME = libftprintf.a
SRC = ft_printf.c
OBJ = $(SRC:.c=.o)
RM = rm -rf

all : $(NAME)

$(NAME) : $(LIB) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(LIB) :
	make -C libft

clean :
	make -C libft clean
	$(RM) $(OBJ)

fclean : clean
	make -C libft fclean
	$(RM) $(NAME)

re : fclean all

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
