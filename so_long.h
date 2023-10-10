/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:56:59 by gvigilan          #+#    #+#             */
/*   Updated: 2023/10/10 21:31:30 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/get_next_line/get_next_line_bonus.h"
# include "./minilibx-linux/mlx.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct space
{
	int	x;
	int	y;
}				t_vec2D;

typedef struct objects
{
	void	*img;
	char	*path;
	int		x;
	int		y;
}				t_col;

typedef struct npc
{
	t_vec2D	pos;
	void	*img;
	char	*path;
	int		health;
	int		x;
	int		y;
}				t_npc;

typedef struct pc
{
	t_vec2D	pos;
	void	*img;
	char	*path;
	int		x;
	int		y;
}				t_pc;

typedef struct e
{
	t_vec2D	pos;
	void	*img;
	char	*path;
	int		x;
	int		y;
}				t_exit;

typedef struct map
{
	void			*t;
	void			*w;
	char			**matrix;
	char			*t_path;
	char			*w_path;
	int		x;
	int		y;
}				t_maps;

typedef struct game
{
	t_col			coll;
	t_npc			frieza;
	t_pc			goku;
	t_exit			uscita;
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	int		counter;
	int		moves;
	t_maps	map;
}				t_game;

enum	e_keys
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	SPACE,
	ESC,
	X,
};

int		check_map_shape(char *path);
int		open_walls(char **map);
char	**read_map(char *path);
int		num_of_collectables(char **map);
int		check_player_and_exit(char **map);
t_vec2D start_pos(t_maps map);
t_vec2D start_exit(t_maps map);
void	start_game(char	*path);
void	put_objects(t_game *g);
void	create_window(t_game *g);
void	setup(char *path, t_game *new);
t_vec2D	start_exit(t_maps map);

#endif
