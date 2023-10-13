/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:50:14 by gvigilan          #+#    #+#             */
/*   Updated: 2023/10/13 16:27:02 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vec2D	start_exit(t_maps map)
{
	t_vec2D	exit_pos;
	int		i;
	int		j;

	i = 0;
	exit_pos.x = 0;
	exit_pos.y = 0;
	while (map.matrix[i])
	{
		j = 0;
		while (map.matrix[i][j])
		{
			if (map.matrix[i][j] == 'E')
			{
				exit_pos.x = i;
				exit_pos.y = j;
				return (exit_pos);
			}
			j++;
		}
		i++;
	}
	return (exit_pos);
}

int	end(t_game *g)
{
	if (g->counter == 0)
	{
		if (g->goku.pos.x == g->uscita.pos.x)
		{
			if (g->goku.pos.y == g->uscita.pos.y)
				return (1);
			else 
				return (0);
		}
	}
	else
		return (0);
	return (0);
}

void	free_all(t_game *g)
{
	free(g->map.matrix);
	free(g->matrix);
	mlx_destroy_image(g->mlx, g->coll.img);
	mlx_destroy_image(g->mlx, g->frieza.img);
	mlx_destroy_image(g->mlx, g->goku.img);
	mlx_destroy_image(g->mlx, g->map.t);
	mlx_destroy_image(g->mlx, g->map.w);
	mlx_destroy_image(g->mlx, g->uscita.img);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g);
}
