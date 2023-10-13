/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:41:06 by gvigilan          #+#    #+#             */
/*   Updated: 2023/10/13 16:28:32 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sq(t_game *game, int x, int y, char a)
{
	if (game->matrix[x][y - 1] == a || game->matrix[x - 1][y] == a ||
	game->matrix[x][y + 1] == a || game->matrix[x + 1][y] == a)
		return (1);
	else
		return (0);
}

void	changeit(t_game *game, int a, int b)
{
	if (game->matrix[a][b] == '0')
		game->matrix[a][b] = '2';
	else if (game->matrix[a][b] == '2')
		game->matrix[a][b] = '0';
	if (game->matrix[a][b] == 'E')
		game->matrix[a][b] = 'U';
	else if (game->matrix[a][b] == 'U')
		game->matrix[a][b] = 'E';
	if (game->matrix[a][b] == 'C')
		game->matrix[a][b] = 'S';
	else if (game->matrix[a][b] == 'S')
		game->matrix[a][b] = 'C';
	if (game->matrix[a][b] == 'N')
		game->matrix[a][b] = 'M';
	else if (game->matrix[a][b] == 'M')
		game->matrix[a][b] = 'N';
	return ;
}

int	controlpath(t_game *game)
{
	int	a;
	int	b;

	a = 0;
	while (game->matrix[a])
	{
		b = 0;
		while (game->matrix[a][b])
		{
			if ((game->matrix[a][b] == '0' || 
				game->matrix[a][b] == 'E' || 
				game->matrix[a][b] == 'C' || 
				game->matrix[a][b] == 'N') && 
			(sq(game, a, b, 'P') || 
			sq(game, a, b, '2') || sq(game, a, b, 'U') || 
			sq(game, a, b, 'S') || sq(game, a, b, 'M')))
			{
				changeit(game, a, b);
				return (controlpath(game));
			}
			b++;
		}
		a++;
	}
	return (0);
}

int	scan(t_game *game)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (game->matrix[a])
	{
		b = 0;
		while (game->matrix[a][b])
		{
			if (game->matrix[a][b] == 'C' || 
				game->matrix[a][b] == 'E' || 
				game->matrix[a][b] == '0')
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

int	pathfind(t_game *game)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	controlpath(game);
	if (scan(game))
	{
		while (game->matrix[a])
		{
			b = 0;
			while (game->matrix[a][b])
			{
				if (game->matrix[a][b] == '2' || 
				game->matrix[a][b] == 'S' ||
				game->matrix[a][b] == 'U' || game->matrix[a][b] == 'M')
					changeit(game, a, b);
				b++;
			}
			a++;
		}
		return (1);
	}
	else
		return (0);
}
