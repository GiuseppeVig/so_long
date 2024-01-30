/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:56:59 by gvigilan          #+#    #+#             */
/*   Updated: 2024/01/30 13:56:22 by gvigilan         ###   ########.fr       */
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
# include <stdio.h>

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
	t_vec2D	spot;
	void	*img;
	char	*path;
	int		health;
	int		x;
	int		y;
}				t_npc;

typedef	struct after
{
	t_vec2D	tp;
	void	*img;
	char	*path;
}				t_after;

typedef struct pc
{
	t_vec2D	pos;
	t_after	tp;
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
	char			*t_path;
	char			*w_path;
	char			**matrix;
	int		x;
	int		y;
	int		h;
	int		wi;
}				t_maps;

typedef struct game
{
	t_col			coll;
	t_npc			frieza;
	t_pc			goku;
	t_exit			uscita;
	char			**matrix;
	int		mode;
	char	*percorso;
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	int		counter;
	int		moves;
	t_maps	map;
}				t_game;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

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
int		check_p_and_e(char **map);
t_vec2D start_pos(t_maps map);
t_vec2D start_exit(t_maps map);
void	start_game(char	*path, int mode);
void	put_objects(t_game *g, int print);
void	create_window(t_game *g);
void	setup(char *path, t_game *new);
t_vec2D	start_exit(t_maps map);
void	free_all(t_game *g);
int	adjust_status(t_game *g, t_vec2D pos);
int		move(int k, t_game *g);
void    move_horizonta(t_game *g, int i);
void    move_vertical(t_game *g, int i);
int		end(t_game *g);
int		key_hook(int keycode);
void	update_player(t_game *g, t_vec2D pos);
void	update_enemy(t_game *g, t_vec2D pos);
int		sq(t_game *game, int x, int y, char a);
void	changeit(t_game *game, int a, int b);
int		controlpath(t_game *game);
int		scan(t_game *game);
int		pathfind(t_game *game);
int 	check_intruder(t_game *g);
int		run_full_check(t_game *g);
void	special_move(t_game	*g);
int		ml(t_game *g);
int		mh(t_game *g);
t_vec2D	start_pos_enemy(t_maps map);
void	enemy_status(t_game *g, t_vec2D pos);
int		move_around(t_game *g);
void	move_to_spot(t_game *g);
int		see_player(t_game *g);
void	move_enemy(t_game *g, int i);
int	adjust_status_player2(t_game *g, t_vec2D pos);
int	move_player2(int k, t_game *g);
void	move_horizontal_player2(t_game *g, int i);
void	move_vertical_player2(t_game *g, int i);
int		allowed_move_side(t_game *g, t_vec2D pos, int i);
int		allowed_move_up_down(t_game *g, t_vec2D pos, int i);
void	print_map(t_game *g);


#endif
