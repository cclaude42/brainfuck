##################################################
# COMPILER
##################################################

NAME = brainfuck

CC = clang

CFLAGS = -Wall -Wextra -Werror

##################################################
# SRC
##################################################

SRC = brainfuck.c

OBJ = $(SRC:c=o)

##################################################
# METHODS
##################################################

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
