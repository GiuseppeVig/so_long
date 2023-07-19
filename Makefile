NAME = so_long
INCLUDES = -I /usr/local/include
LINKER = -L /usr/local/lib
SRCS_DIR = ./srcs
SRCS = so_long.c map_checker.c
FLAGS = -Wall -Werror -Wextra
PRINTF = ./ft_printf/libftprintf.a
MLX_MAC = -lmlx -framework OpenGL -framework AppKit
MLX_LINUX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Ilml_linux -lm -lz -lXext -lX11
OBJS = ${SRCS:%.c=%.o}
GCC = gcc
GNL = ./ft_printf/get_next_line/get_next_line.a

all: $(NAME)

$(NAME): $(OBJS)
	cd ft_printf && make
	cd ft_printf/get_next_line && make
	gcc $(FLAGS) $(OBJS) $(PRINTF) $(GNL) $(MLX_MAC) -o $(NAME)

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