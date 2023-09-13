NAME = so_long
INCLUDES = -I /usr/local/include
LINKER = -L /usr/local/lib
SRCS_DIR = ./srcs
SRCS = so_long.c map_checker.c
FLAGS = -Wall -Werror -Wextra
PRINTF = ./ft_printf/libftprintf.a
MLX_MAC = -lmlx -framework OpenGL -framework AppKit
MLX_LINUX = -L/minilibx-linux -Ilml_linux -lm -lz -lXext -lX11
OBJS = ${SRCS:%.c=%.o}
GCC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	cd minilibx-linux && make
	cd ft_printf && make
	gcc $(FLAGS) $(OBJS) $(PRINTF) $(MLX_LINUX) -o $(NAME)

%.o: %.c
	$(GCC) $(FLAGS) -c $<

clean:
	rm -fr $(OBJS)
	cd ft_printf && make clean
	cd ft_printf/get_next_line && make clean

fclean: clean
	rm -fr so_long
	cd ft_printf && make fclean
	cd ft_printf/get_next_line && make fclean

re: fclean all