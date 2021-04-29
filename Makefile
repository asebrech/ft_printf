# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asebrech <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 16:13:10 by asebrech          #+#    #+#              #
#    Updated: 2021/04/29 18:18:19 by asebrech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DLIB = libft
PLIB = libft/libft.a
NAME = libftprintf.a
SRC = ft_printf.c ft_printf_utiles.c
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
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

.PHONY : all clean fclean re
