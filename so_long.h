/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:56:59 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/14 02:41:30 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "./ft_printf/ft_printf.h"
# include "./ft_printf/get_next_line/get_next_line_bonus.h"
# include <math.h>

typedef struct space
{
    int position_x;
    int position_y;    
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

typedef	struct map
{
	sprites	objects;
	int		collider;
}				maps;

typedef struct pc
{
	vec2D	position;
	sprites	model;
	int		collider;
	int		hit;
}				player;

int	check_map_shape(char *location, char *name);

#endif