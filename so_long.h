/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:56:59 by gvigilan          #+#    #+#             */
/*   Updated: 2023/09/18 19:03:20 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/get_next_line/get_next_line_bonus.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct space
{
    int	position_x;
    int	position_y;
}				vec2D;

typedef	struct images
{
	void	*mlx;
	void	*img;
	char	*path;
	int		width;
	int		height;
}				sprites;

typedef struct objects
{
	sprites	models;
	vec2D	position;
}				collectables;

typedef struct npc
{
	sprites	models;
	vec2D	position;
	vec2D	movement;
	int		health;
}				enemies;

typedef struct pc
{
	vec2D	position;
	sprites	model;
}				player;

typedef struct e
{
	vec2D	position;
	char	*path;
}				exit_t;

typedef	struct map
{
	sprites			tiles;
	sprites			walls;
	collectables	coll;
	enemies			frieza;
	player			goku;
	exit_t			uscita;
	char			**matrix;
	char			*path;
	int				collider;
	void			*mlx;
	void			*win;
}				maps;


enum	keys
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	SPACE,
	ESC,
	X,
};

int		check_map_shape(maps m);
int		open_walls_horizontal(maps m);
int		open_walls_vertical(maps m);
char	**read_map(maps m);
int		control_map(maps mappa);

#endif
