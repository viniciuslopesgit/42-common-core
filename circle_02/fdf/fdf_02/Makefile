# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/06 00:13:35 by vilopes           #+#    #+#              #
#    Updated: 2025/04/17 21:41:00 by vilopes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do executável
NAME = fdf

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Ficheiros fonte
SRC = src/fdf.c \
      files/draw_lines.c \
	  files/color.c \
      files/ultils.c \
	  files/zoom.c \
	  files/free_mem.c \
      libft/get_next_line/get_next_line.c \
      libft/get_next_line/get_next_line_utils.c \
	  libft/ft_atoi.c \
	  libft/ft_memset.c  

# Ficheiros objeto
OBJ = $(SRC:.c=.o)

# Diretório da MiniLibX
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Includes (cabeçalhos)
INCLUDES = -Iincludes -I$(MLX_DIR) -Ilibft/get_next_line

# Regra principal
all: $(MLX_LIB) $(NAME)

# Compilar a MiniLibX
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

# Ligar os objetos pra criar o executável
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

# Compilar cada .c em .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Limpar ficheiros objeto
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean

# Limpar tudo (inclui o executável)
fclean: clean
	rm -f $(NAME)

# Recompilar do zero
re: fclean all

# Declarações phony
.PHONY: all clean fclean re