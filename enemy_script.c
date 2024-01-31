/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_script.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:50:19 by gvigilan          #+#    #+#             */
/*   Updated: 2024/01/31 17:31:22 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_game *g, int i)
{
	t_vec2D pos;

	pos = g->frieza.pos;
	if (i == 1 && g->matrix[pos.x][pos.y + 1] != '1' && allowed_move_side(g, pos, 1))
	{
		g->frieza.pos.y += 1;
		enemy_status(g, pos);
	}
	else if (i == 2 && g->matrix[pos.x][pos.y - 1] != '1' && allowed_move_side(g, pos, 2))
	{
		g->frieza.pos.y -= 1;
		enemy_status(g, pos);
	}
	else if (i == 3 && g->matrix[pos.x + 1][pos.y] != '1' && allowed_move_up_down(g, pos, 1))
	{
		g->frieza.pos.x += 1;
		enemy_status(g, pos);
	}
	else if (i == 4 && g->matrix[pos.x - 1][pos.y] != '1' && allowed_move_up_down(g, pos, 2))
	{
		g->frieza.pos.x -= 1;
		enemy_status(g, pos);
	}
	else if (g->matrix[pos.x - 1][pos.y] == '1' || g->matrix[pos.x + 1][pos.y] == '1')
		g->frieza.spot.x = 0;
	else if (g->matrix[pos.x][pos.y + 1] == '1' || g->matrix[pos.x][pos.y - 1] == '1')
		g->frieza.spot.x = 0;
	else
		i++;
}

int	see_player(t_game *g)
{
	t_vec2D	pos;

	pos = g->goku.pos;
	if (g->frieza.pos.x == pos.x)
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
		g->frieza.spot = pos;
		return (1);
	}
	else if (g->frieza.pos.y == pos.y)
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
		g->frieza.spot = pos;
		return (1);
	}
	return (0);
}

void	move_to_spot(t_game *g)
{
	static int x;

	if ((g->frieza.pos.x != g->frieza.spot.x || g->frieza.pos.y != g->frieza.spot.y) && x != 1000)
	{
		if (g->frieza.pos.y < g->frieza.spot.y)
			move_enemy(g, 1);
		else if (g->frieza.pos.y > g->frieza.spot.y)
			move_enemy(g, 2);
		else if (g->frieza.pos.x < g->frieza.spot.x)
			move_enemy(g, 3);
		else if (g->frieza.pos.x > g->frieza.spot.x)
			move_enemy(g, 4);
		if (g->frieza.pos.x == g->frieza.spot.x && g->frieza.pos.y == g->frieza.spot.y)
			g->frieza.spot.x = 0;
	}
	x++;
}

int	move_around(t_game *g)
{
	int	i;
	static int x;
	int	time;

	if (see_player(g) || g->frieza.spot.x != 0)
		time = 2000;
	else
		time = 3000;
	i = (rand() % (4 - 1 + 1)) + 1;
	if (!end(g) && x == time)
	{
		if (see_player(g) || g->frieza.spot.x != 0)
		{
			if (g->frieza.spot.x != 0)
				move_to_spot(g);
		}
		else if (i == 2)
				move_enemy(g, i);
		else if (i == 3)
				move_enemy(g, i);
		else if (i == 4)
				move_enemy(g, i);
		else if (i == 1)
				move_enemy(g, i);
		x = 0;
	}
	if (x > 3000)
		x = 0;
	x++;
	return (1);
}

void	enemy_status(t_game *g, t_vec2D pos)
{
	g->matrix[pos.x][pos.y] = '0';
	if (g->matrix[g->frieza.pos.x][g->frieza.pos.y] != 'E' && g->matrix[pos.x][pos.y] != 'A')
		g->matrix[g->frieza.pos.x][g->frieza.pos.y] = 'N';
	create_window(g);
	put_objects(g, 0);
	update_enemy(g, pos);
}
