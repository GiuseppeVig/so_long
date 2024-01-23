/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_script.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:50:55 by gvigilan          #+#    #+#             */
/*   Updated: 2024/01/23 02:28:25 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vec2D	start_pos(t_maps map)
{
	t_vec2D	start;
	int		x;
	int		y;

	x = 0;
	start.x = 0;
	start.y = 0;
	while (map.matrix[x])
	{
		y = 0;
		while (map.matrix[x][y])
		{
			if (map.matrix[x][y] == 'P')
			{
				start.x = x;
				start.y = y;
				return (start);
			}
			y++;
		}
		x++;
	}
	return (start);
}

void	move_vertical(t_game *g, int i)
{
	t_vec2D	pos;

	pos = g->goku.pos;
	if (i == 1)
	{
		if (g->matrix[pos.x + 1][pos.y] != '1')
		{
			g->goku.pos.x += 1;
			if (g->matrix[pos.x + 1][pos.y] == 'C')
				g->counter--;
			g->moves++;
			adjust_status(g, pos);
		}
	}
	if (i == 2)
	{
		if (g->matrix[pos.x - 1][pos.y] != '1')
		{
			g->goku.pos.x -= 1;
			if (g->matrix[pos.x - 1][pos.y] == 'C')
				g->counter--;
			g->moves++;
			adjust_status(g, pos);
		}
	}
}

void	move_horizonta(t_game *g, int i)
{
	t_vec2D	pos;

	pos = g->goku.pos;
	if (i == 1)
	{
		if (g->matrix[pos.x][pos.y + 1] != '1')
		{
			g->goku.pos.y += 1;
			if (g->matrix[pos.x][pos.y + 1] == 'C')
				g->counter--;
			g->moves++;
			adjust_status(g, pos);
		}
	}
	if (i == 2)
	{
		if (g->matrix[pos.x][pos.y - 1] != '1')
		{
			g->goku.pos.y -= 1;
			if (g->matrix[pos.x][pos.y - 1] == 'C')
				g->counter--;
			g->moves++;
			adjust_status(g, pos);
		}
	}
}

void	special_move(t_game	*g)
{
	t_vec2D	pos;

	pos = g->goku.pos;
	if (g->goku.tp.tp.x != 0 && g->goku.tp.tp.y != 0)
	{
		if (g->goku.tp.tp.x != g->goku.pos.x && g->goku.tp.tp.y != g->goku.pos.y)
		{
			g->moves++;
			g->goku.pos = g->goku.tp.tp;
			adjust_status(g, pos);
			g->goku.tp.tp.x = 0;
			g->goku.tp.tp.y = 0;
		}
	}
	else if (g->goku.tp.tp.x != g->goku.pos.x || g->goku.tp.tp.y != g->goku.pos.y)
	{
		g->moves++;
		g->goku.tp.tp = g->goku.pos;
		if (g->goku.tp.tp.x != 0 && g->goku.tp.tp.y != 0)
			g->matrix[g->goku.pos.x][g->goku.pos.y] = 'A';
		adjust_status(g, pos);
	}
}

int	move_player2(int k, t_game *g)
{
	if (k == 105)
		move_vertical_player2(g, 2);
	else if (k == 107)
		move_vertical_player2(g, 1);
	else if (k == 108)
		move_horizontal_player2(g, 1);
	else if (k == 106)
		move_horizontal_player2(g, 2);
	return (0);
}

int	move(int k, t_game *g)
{
	if (k == 13 || k == 119)
		move_vertical(g, 2);
	else if (k == 1 || k == 115)
		move_vertical(g, 1);
	else if (k == 2 || k == 100)
		move_horizonta(g, 1);
	else if (k == 0 || k == 97)
		move_horizonta(g, 2);
	else if (k == 32)
		special_move(g);
	else if (k == 65307)
	{
		free_all(g);
		exit(0);
	}
	else if (g->mode != 0)
		move_player2(k, g);
	return (0);
}

int	adjust_status(t_game *g, t_vec2D pos)
{
	if (end(g))
	{
		free_all(g);
		exit(0);
	}
	if (g->matrix[pos.x][pos.y] != 'E' && g->matrix[pos.x][pos.y] != 'A')
		g->matrix[pos.x][pos.y] = '0';
	if (g->matrix[g->goku.pos.x][g->goku.pos.y] != 'E' && g->matrix[pos.x][pos.y] != 'A')
		g->matrix[g->goku.pos.x][g->goku.pos.y] = 'P';
	create_window(g);
	put_objects(g, 1);
	update_player(g, pos);
	return (1);
}



