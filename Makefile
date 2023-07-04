NAME = so_long
INCLUDES = -I /usr/local/include
LINKER = -L /usr/local/lib
SRCS_DIR = ./srcs
SRCS = test.c
FLAGS = -Wall -Werror -Wextra
MLX_MAC = -lmlx -framework OpenGL -framework AppKit
MLX_LINUX = -lmlx -lXext -lX11
OBJS = ${SRCS: %.c=%.o}

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS) $(SRCS) $(MLX_MAC) -o $(NAME)