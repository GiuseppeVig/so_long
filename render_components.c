/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_components.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:49:29 by gvigilan          #+#    #+#             */
/*   Updated: 2023/09/18 17:46:27 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assign_walls_and_floor(maps to_render)
{
	int	i;
	int	j;

	to_render.matrix = read_map(to_render);
	to_render.tiles.path = "./sprites/terrain/floor.xpm";
	to_render.walls.path = "./sprites/terrain/wall.xpm";
	i = 0;
	while (to_render.matrix[i])
	{
		j = 0;
		while (to_render.matrix[i][j])
		{
			if (to_render.matrix[i][j] == '1')
				to_render.walls.path.img = mlx_xpm_file_to_image(to_render.mlx, to_render.walls.path, 32, 32);
			if (to_render.matrix[i][j] == '0')
				to_render.walls.path.img =  mlx_xpm_file_to_image(to_render.mlx, to_render.tiles.path, 32, 32);
			j++;
		}
		i++;
	}
}
