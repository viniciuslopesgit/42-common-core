# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/07 22:36:54 by vilopes           #+#    #+#              #
#    Updated: 2024/12/09 21:50:02 by vilopes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = 	$(wildcard ./Libft/*.c) \
		$(wildcard ./Printf/files/*.c)

OBJ = $(SRC:.c=.o)

all: 	$(NAME)
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
