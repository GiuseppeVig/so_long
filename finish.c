/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:50:14 by gvigilan          #+#    #+#             */
/*   Updated: 2023/10/10 21:02:36 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vec2D	start_exit(t_maps map)
{
	t_vec2D exit_pos;
	int     i;
	int     j;

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

// int	end(t_game *g)
// {
// 	if (g->counter == 0)
// 	{
// 		if (g->map.goku.pos.x == g->map.uscita.pos.x)
// 			if (g->map.goku.pos.y == g->map.uscita.pos.y)
// 				return (1);
// 		else 
// 			return (0);
// 	}
// 	else
// 		return (0);
// }

// void	free_all(t_game *g)
// {
// 	if (end(g))
// 	{
// 		free(g->map.matrix);
// 		mlx_destroy_image(g->mlx, g->map.coll.img);
// 		mlx_destroy_image(g->mlx, g->map.frieza.img);
// 		mlx_destroy_image(g->mlx, g->map.goku.img);
// 		mlx_destroy_image(g->mlx, g->map.tiles);
// 		mlx_destroy_image(g->mlx, g->map.walls);
// 		mlx_destroy_image(g->mlx, g->map.uscita.img);
// 		mlx_destroy_window(g->mlx, g->win);
// 		mlx_destroy_display(g->mlx);
// 		free(g);
// 	}
// }
