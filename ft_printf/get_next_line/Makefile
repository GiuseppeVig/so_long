NAME = get_next_line.a
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:%.c=%.o)
CC = gcc -c
FLAGS = -Werror -Wall -Wextra

all : $(NAME)
$(NAME) :
	$(CC) $(FLAGS) -I ./ $(SRC)
	ar rcs $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all