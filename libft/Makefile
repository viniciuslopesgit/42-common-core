# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 22:01:31 by vilopes           #+#    #+#              #
#    Updated: 2024/11/05 21:31:36 by vilopes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c
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
	
