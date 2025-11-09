# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 18:39:09 by viniciuslop       #+#    #+#              #
#    Updated: 2025/04/04 22:54:55 by vilopes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER 			= server
CLIENT 			= client

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror

SRC_DIR			= src/
FT_PRINTF_DIR	= files/libft/printf/
TALK_DIR		= files/talk/


COMMANDS 		= $(FT_PRINTF_DIR)ft_numbers.c \
				$(FT_PRINTF_DIR)ft_printf.c \
				$(FT_PRINTF_DIR)ft_strs.c \
				$(TALK_DIR)talk_utils.c

SRCS_SERVER		= $(SRC_DIR)server.c $(COMMANDS)
SRCS_CLIENT		= $(SRC_DIR)client.c $(COMMANDS)

OBJS_SERVER		= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT		= $(SRCS_CLIENT:.c=.o)


# Regra principal
all: $(SERVER) $(CLIENT)

# Compilar o programa
$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(SERVER)
	
$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(CLIENT)
	
$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_SERVER) $(OBJS_CLIENT)
fclean: clean
	rm -rf $(SERVER) $(CLIENT)
re: fclean all
