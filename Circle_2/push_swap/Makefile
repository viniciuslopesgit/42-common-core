# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 22:08:42 by vilopes           #+#    #+#              #
#    Updated: 2025/02/13 23:01:18 by vilopes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

COMMA_DIR = files/commands/
LIBFT_DIR = files/libft/
STACK_DIR = files/stacks/

COMMANDS = $(COMMA_DIR)is_sorted.c \
           $(COMMA_DIR)swap.c

PUSH_SWAP = $(LIBFT_DIR)ft_atoi.c \
            $(LIBFT_DIR)ft_numbers.c \
            $(LIBFT_DIR)ft_printf.c \
            $(LIBFT_DIR)ft_split.c \
            $(LIBFT_DIR)ft_strs.c \
            $(STACK_DIR)stacks.c \
            $(STACK_DIR)syntax.c

MAIN = src/push_swap.c

SRCS = $(COMMANDS) $(PUSH_SWAP) $(MAIN)

OBJ = $(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)libft.a
	$(CC) $(CFLAGS) -I inc -o $(NAME) $(OBJ) $(LIBFT_DIR)libft.a

$(OBJ): %.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I inc -c $< -o $@

$(LIBFT_DIR)libft.a:
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT_DIR)libft.a

re: fclean all
