/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:10:43 by gvigilan          #+#    #+#             */
/*   Updated: 2023/10/11 14:11:46 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    update_win(t_game *g, t_vec2D pos)
{
    if (pos.y < g->goku.pos.y || pos.y > g->goku.pos.y)
	{
		g->goku.path = "./sprites/PC/move_side.xpm";
		g->goku.img = mlx_xpm_file_to_image(g->mlx, g->goku.path, &g->x, &g->y);
		mlx_put_image_to_window(g->mlx, g->win, g->goku.img,
		g->goku.pos.y * 32, g->goku.pos.x * 32);
	}
	if (pos.x < g->goku.pos.x)
	{
		g->goku.path = "./sprites/PC/move_down.xpm";
		g->goku.img = mlx_xpm_file_to_image(g->mlx, g->goku.path, &g->x, &g->y);
		mlx_put_image_to_window(g->mlx, g->win, g->goku.img,
		g->goku.pos.y * 32, g->goku.pos.x * 32);
	}
	if (pos.x > g->goku.pos.x)
	{
		g->goku.path = "./sprites/PC/move_up.xpm";
		g->goku.img = mlx_xpm_file_to_image(g->mlx, g->goku.path, &g->x, &g->y);
		mlx_put_image_to_window(g->mlx, g->win, g->goku.img,
		g->goku.pos.y * 32, g->goku.pos.x * 32);
	}
}