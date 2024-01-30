/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:21:55 by gvigilan          #+#    #+#             */
/*   Updated: 2024/01/30 13:55:23 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		allowed_move_up_down(t_game *g, t_vec2D pos, int i)
{
	int	move;

	if (g->mode == 1)
		move = 2;
	else
		move = 1;
	if (i == 1)
	{
		if (g->matrix[pos.x + move][pos.y] != 'C' && g->matrix[pos.x + move][pos.y] != 'E')
			return(1);
		return (0);
	}
	if (i == 2)
	{
		if (g->matrix[pos.x - move][pos.y] != 'C' && g->matrix[pos.x + move][pos.y] != 'E')
			return(1);
		return (0);
	}
	return (0);
}

int		allowed_move_side(t_game *g, t_vec2D pos, int i)
{
	int	move;

	if (g->mode == 1)
		move = 2;
	else
		move = 1;
	if (i == 1)
	{
		if (g->matrix[pos.x][pos.y + move] != 'C' && g->matrix[pos.x][pos.y + move] != 'E')
			return(1);
		return (0);
	}
	if (i == 2)
	{
		if (g->matrix[pos.x][pos.y - move] != 'C' && g->matrix[pos.x][pos.y - move] != 'E')
			return(1);
		return (0);
	}
	return (0);
}

void	move_vertical_player2(t_game *g, int i)
{
	t_vec2D	pos;

	pos = g->frieza.pos;
	if (i == 1)
	{
		if (g->matrix[pos.x + 2][pos.y] != '1' && allowed_move_up_down(g, pos, 1))
		{
			g->frieza.pos.x += 2;
			adjust_status_player2(g, pos);
		}
	}
	if (i == 2)
	{
		if (g->matrix[pos.x - 2][pos.y] != '1' && allowed_move_up_down(g, pos, 2))
		{
			g->frieza.pos.x -= 2;
			adjust_status_player2(g, pos);
		}
	}
}

void	move_horizontal_player2(t_game *g, int i)
{
	t_vec2D	pos;

	pos = g->frieza.pos;
	if (i == 1)
	{
		if (g->matrix[pos.x][pos.y + 1] != '1' && allowed_move_side(g, pos, 1))
		{
			g->frieza.pos.y += 2;
			adjust_status_player2(g, pos);
		}
	}
	if (i == 2)
	{
		if (g->matrix[pos.x][pos.y - 1] != '1' && allowed_move_side(g, pos, 2))
		{
			g->frieza.pos.y -= 2;
			adjust_status_player2(g, pos);
		}
	}
}

int	adjust_status_player2(t_game *g, t_vec2D pos)
{
	if (end(g))
	{
		free_all(g);
		exit(0);
	}
	if (g->matrix[pos.x][pos.y] != 'E' && g->matrix[pos.x][pos.y] != 'C')
		g->matrix[pos.x][pos.y] = '0';
	if (g->matrix[g->frieza.pos.x][g->frieza.pos.y] != 'E' || g->matrix[pos.x][pos.y] != 'C')
		g->matrix[g->frieza.pos.x][g->frieza.pos.y] = 'N';
	create_window(g);
	put_objects(g, 0);
	update_enemy(g, pos);
	return (1);
}
