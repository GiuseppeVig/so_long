/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_script.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:50:19 by gvigilan          #+#    #+#             */
/*   Updated: 2024/01/22 22:08:58 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_game *g, int i)
{
	t_vec2D pos;

	pos = g->frieza.pos;
	if (i == 1)
	{
		g->frieza.pos.y += 1;
		enemy_status(g, pos);
	}
	else if (i == 2)
	{
		g->frieza.pos.y -= 1;
		enemy_status(g, pos);
	}
	else if (i == 3)
	{
		g->frieza.pos.x += 1;
		enemy_status(g, pos);
	}
	else if (i == 4)
	{
		g->frieza.pos.x -= 1;
		enemy_status(g, pos);
	}
}

int	see_player(t_game *g)
{
	t_vec2D	pos;

	pos = g->goku.pos;
	if (g->frieza.pos.x == g->goku.pos.x)
	{
		while (pos.x != g->frieza.pos.x)
		{
			if (g->map.matrix[pos.x][pos.y] == '1')
				return (0);
			else if (g->frieza.pos.x < pos.x)
				pos.x--;
			else
				pos.x++;
		}
	}
	else if (g->frieza.pos.y == g->goku.pos.y)
	{
		while (pos.y != g->frieza.pos.y)
		{
			if (g->map.matrix[pos.x][pos.y] == '1')
				return (0);
			else if (g->frieza.pos.y < pos.y)
				pos.y--;
			else
				pos.y++;
		}
	}
	return (1);
}

void	move_to_spot(t_game *g)
{
	g->frieza.spot = g->goku.pos;

	while (g->frieza.pos.x != g->frieza.spot.x && g->frieza.pos.y != g->frieza.spot.y)
	{
		while (g->frieza.pos.y < g->frieza.spot.y)
			move_enemy(g, 1);
		while (g->frieza.pos.y > g->frieza.spot.y)
			move_enemy(g, 2);
		while (g->frieza.pos.x < g->frieza.spot.x)
			move_enemy(g, 3);
		while (g->frieza.pos.x > g->frieza.spot.x)
			move_enemy(g, 4);
	}
}

int	move_around(t_game *g)
{
	int	i;

	i = (rand() % (4 - 1 + 1)) + 1;
	mlx_key_hook(g->win, move, g);
	if (!end(g))
	{
		usleep(1000000);
		if (i == 1 && !see_player(g))
		{
			while (g->frieza.pos.y + 1 != '1')
				move_enemy(g, i);
		}
		else if (i == 2 && !see_player(g))
		{
			while (g->frieza.pos.y - 1 != '1')
				move_enemy(g, i);
		}
		else if (i == 3 && !see_player(g))
		{
			while (g->frieza.pos.x + 1 != '1')
				move_enemy(g, i);
		}
		else if (i == 4 && !see_player(g))
		{
			while (g->frieza.pos.x + 1 != '1')
				move_enemy(g, i);
		}
		else if (see_player(g))
			move_to_spot(g);
	}
	return (1);
}

void	enemy_status(t_game *g, t_vec2D pos)
{
	g->matrix[pos.x][pos.y] = '0';
	if (g->matrix[g->goku.pos.x][g->goku.pos.y] != 'E' && g->matrix[pos.x][pos.y] != 'A')
		g->matrix[g->goku.pos.x][g->goku.pos.y] = 'N';
	create_window(g);
	put_objects(g, 0);
	update_enemy(g, pos);
}
