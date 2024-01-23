/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:10:43 by gvigilan          #+#    #+#             */
/*   Updated: 2024/01/23 02:14:48 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player(t_game *g, t_vec2D pos)
{
	if (pos.x !=  g->goku.pos.x && pos.y !=  g->goku.pos.y )
	{
		mlx_put_image_to_window(g->mlx, g->win, g->map.t,
					g->goku.pos.y * 32, g->goku.pos.x * 32);
		g->goku.path = "./sprites/PC/idle.xpm";
		g->goku.img = mlx_xpm_file_to_image(g->mlx, g->goku.path, &g->x, &g->y);
		mlx_put_image_to_window(g->mlx, g->win, g->goku.img,
			g->goku.pos.y * 32, g->goku.pos.x * 32);
	}
	else if (pos.y < g->goku.pos.y || pos.y > g->goku.pos.y)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->map.t,
					g->goku.pos.y * 32, g->goku.pos.x * 32);
		g->goku.path = "./sprites/PC/move_side.xpm";
		g->goku.img = mlx_xpm_file_to_image(g->mlx, g->goku.path, &g->x, &g->y);
		mlx_put_image_to_window(g->mlx, g->win, g->goku.img,
			g->goku.pos.y * 32, g->goku.pos.x * 32);
	}
	else if (pos.x < g->goku.pos.x)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->map.t,
					g->goku.pos.y * 32, g->goku.pos.x * 32);
		g->goku.path = "./sprites/PC/move_down.xpm";
		g->goku.img = mlx_xpm_file_to_image(g->mlx, g->goku.path, &g->x, &g->y);
		mlx_put_image_to_window(g->mlx, g->win, g->goku.img,
			g->goku.pos.y * 32, g->goku.pos.x * 32);
	}
	else if (pos.x > g->goku.pos.x)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->map.t,
					g->goku.pos.y * 32, g->goku.pos.x * 32);
		g->goku.path = "./sprites/PC/move_up.xpm";
		g->goku.img = mlx_xpm_file_to_image(g->mlx, g->goku.path, &g->x, &g->y);
		mlx_put_image_to_window(g->mlx, g->win, g->goku.img,
			g->goku.pos.y * 32, g->goku.pos.x * 32);
	}
}

void	update_enemy(t_game *g, t_vec2D pos)
{
	print_map(g);
	if (pos.y < g->frieza.pos.y || pos.y > g->frieza.pos.y)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->map.t,
					g->frieza.pos.y * 32, g->frieza.pos.x * 32);
		g->frieza.path = "./sprites/NPC/moveside01.xpm";
		g->frieza.img = mlx_xpm_file_to_image(g->mlx, g->frieza.path, &g->frieza.x, &g->frieza.y);
		mlx_put_image_to_window(g->mlx, g->win, g->goku.img,
			g->frieza.pos.y * 32, g->frieza.pos.x * 32);
	}
	if (pos.x < g->frieza.pos.x)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->map.t,
					g->frieza.pos.y * 32, g->frieza.pos.x * 32);
		g->frieza.path = "./sprites/NPC/movedown01.xpm";
		g->frieza.img = mlx_xpm_file_to_image(g->mlx, g->frieza.path, &g->x, &g->y);
		mlx_put_image_to_window(g->mlx, g->win, g->frieza.img,
			g->frieza.pos.y * 32, g->frieza.pos.x * 32);
	}
	if (pos.x > g->frieza.pos.x)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->map.t,
					g->frieza.pos.y * 32, g->frieza.pos.x * 32);
		g->frieza.path = "./sprites/NPC/moveup01.xpm";
		g->frieza.img = mlx_xpm_file_to_image(g->mlx, g->frieza.path, &g->x, &g->y);
		mlx_put_image_to_window(g->mlx, g->win, g->frieza.img,
			g->frieza.pos.y * 32, g->frieza.pos.x * 32);
	}
}
