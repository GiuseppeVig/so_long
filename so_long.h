/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:56:59 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/16 12:34:14 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "ft_printf/ft_printf.h"
# include "ft_printf/get_next_line/get_next_line_bonus.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct space
{
    int	position_x;
    int	position_y;
}				vec2D;

typedef	struct images
{
	void	*mlx;
	char	*path;
	int		width;
	int		height;
}				sprites;

typedef struct objects
{
	sprites	models;
	vec2D	position;
	int		collected;
}				collectables;

typedef struct npc
{
	sprites	models;
	vec2D	position;
	vec2D	movement;
}				enemies;

typedef struct pc
{
	vec2D	position;
	sprites	model;
	int		collider;
	int		hit;
}				player;

typedef	struct map
{
	sprites			object;
	collectables	coll;
	enemies			frieza;
	player			goku;
	char			**matrix;
	char			*path;
	int				collider;
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

int	check_map_shape(maps m);

#endif