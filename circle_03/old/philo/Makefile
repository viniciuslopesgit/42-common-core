NAME = philo

CC = cc
FLAGS = -Wall -Wextra -Werror -pthread -03

SRC		=	main.c \
			utils/time.c \
			utils/init.c \
			utils/threads.c \
			utils/monitor.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
