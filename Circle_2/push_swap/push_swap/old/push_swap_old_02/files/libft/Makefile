# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 22:01:31 by vilopes           #+#    #+#              #
#    Updated: 2025/02/13 22:56:23 by vilopes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = ft_atoi.c ft_numbers.c ft_split.c ft_strs.c
OBJ = $(SRC:.c=.o)


# Compile the executable
all: $(NAME)


# Create the executable from the object files
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)


# Compile each ".c" on the ".o"
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


# Clear all object files
clean:
	rm -rf $(OBJ)

# Clear all, include the executable
fclean: clean
	rm -rf $(NAME)

# Reconstruct all
re: fclean all
	
