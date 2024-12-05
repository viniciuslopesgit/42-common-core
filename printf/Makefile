# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 21:10:08 by vilopes           #+#    #+#              #
#    Updated: 2024/12/05 01:10:32 by viniciuslop      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnumber.c ft_itoa.c ft_strlen.c ft_puthex.c ft_putunsigned_int.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all