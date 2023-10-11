/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_script.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:50:55 by gvigilan          #+#    #+#             */
/*   Updated: 2023/10/11 14:12:27 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vec2D start_pos(t_maps map)
{
	t_vec2D start;
	int     x;
	int     y;

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

void    move_vertical(t_game *g, int i)
{
	t_vec2D pos;

	pos = g->goku.pos;
	if (i == 1)
	{
		if (g->map.matrix[pos.x + 1][pos.y] != '1')
		{
			g->goku.pos.x += 1;
			if (g->map.matrix[pos.x + 1][pos.y] == 'C')
				g->counter--;
			g->moves++; 
			adjust_status(g, pos);
		}
	}
	if (i == 2)
	{
		if (g->map.matrix[pos.x - 1][pos.y] != '1')
		{
			g->goku.pos.x -= 1;
			if (g->map.matrix[pos.x - 1][pos.y] == 'C')
				g->counter--;
			g->moves++; 
			adjust_status(g, pos);
		}
	}
}

void    move_horizonta(t_game *g, int i)
{
	t_vec2D pos;

	pos = g->goku.pos;
	if (i == 1)
	{
		if (g->map.matrix[pos.x][pos.y + 1] != '1')
		{
			g->goku.pos.y += 1;
			if (g->map.matrix[pos.x][pos.y + 1] == 'C')
				g->counter--;
			g->moves++;
			adjust_status(g, pos);
		}
	}
	if (i == 2)
	{
		if (g->map.matrix[pos.x][pos.y - 1] != '1')
		{
			g->goku.pos.y -= 1;
			if (g->map.matrix[pos.x][pos.y - 1] == 'C')
				g->counter--;
			g->moves++; 
			adjust_status(g, pos);
		}
	}
}

int		move(int k, t_game *g)
{
	if (k == 13 || k == 119)
	{
		move_vertical(g, 2);
	}
	else if (k == 1 || k == 115)
	{
		move_vertical(g, 1);
	}
	else if (k == 2 || k == 100)
	{
		move_horizonta(g, 1);
	}
	else if (k == 0 || k == 97)
	{
		move_horizonta(g, 2);
	}
	else if (k == 53)
	{
		free_all(g);
		exit(0);
	}
	return (0);
}

void	adjust_status(t_game *g, t_vec2D pos)
{
	if (end(g))
	{
		free_all(g);
		exit(0);
	}
	create_window(g);
	put_objects(g);
	g->map.matrix[pos.x][pos.y] = '0';
	g->map.matrix[g->goku.pos.x][g->goku.pos.y] = 'P';
	update_win(g, pos);
}
