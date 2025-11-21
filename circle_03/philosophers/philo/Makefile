# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/21 21:05:13 by vilopes           #+#    #+#              #
#    Updated: 2025/11/21 21:13:47 by vilopes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -O3

SRC 		= main.c \
			  src/utils.c \
			  src/init.c \
			  src/threads.c \
			  src/monitor.c \
			  src/routine_actions.c

OBJ			= $(SRC:.c=.o)
#SANITIZER	= -fsanitize=thread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(SANITIZER)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re