NAME = so_long
INCLUDES = -I /usr/local/include
LINKER = -L /usr/local/lib
SRCS_DIR = ./srcs
SRCS = so_long.c
FLAGS = -Wall -Werror -Wextra
MLX_MAC = -lmlx -framework OpenGL -framework AppKit
MLX_LINUX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Ilml_linux -lm -lz -lXext -lX11
OBJS = ${SRCS:.c=.o}
GCC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	cd ft_printf && make
	gcc $(FLAGS) $(OBJS) $(MLX_MAC) -o $(NAME)

%.o: %.c
	$(GCC) $(FLAGS) -c $<

clean:
	rm -f $(OBJS)
	cd ft_printf && make clean

fclean: clean
	rm so_long
	cd ft_printf && make fclean

re: fclean all