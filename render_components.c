/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_components.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:49:29 by gvigilan          #+#    #+#             */
/*   Updated: 2023/10/11 14:03:55 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup(char *path, t_game *new)
{
	new->map.matrix = read_map(path);
	new->counter = num_of_collectables(new->map.matrix);
	new->goku.path = "./sprites/PC/idle.xpm";
	new->frieza.path = "./sprites/NPC/idle.xpm";
	new->coll.path = "./sprites/balls/ball.xpm";
	new->uscita.path = "./sprites/exit/exit.xpm";
	new->map.w_path = "./sprites/terrain/wall.xpm";
	new->map.t_path = "./sprites/terrain/floor.xpm";
	new->goku.pos = start_pos(new->map);
	new->frieza.pos = start_pos(new->map);
	new->uscita.pos = start_exit(new->map);
	new->map.w = mlx_xpm_file_to_image(new->mlx, new->map.w_path,
			&new->x, &new->y);
	new->map.t = mlx_xpm_file_to_image(new->mlx, new->map.t_path,
			&new->x, &new->y);
	new->goku.img = mlx_xpm_file_to_image(new->mlx, new->goku.path,
			&new->x, &new->y);
	new->coll.img = mlx_xpm_file_to_image(new->mlx, new->coll.path,
			&new->x, &new->y);
	new->uscita.img = mlx_xpm_file_to_image(new->mlx, new->uscita.path,
			&new->x, &new->y);
	new->frieza.img = mlx_xpm_file_to_image(new->mlx, new->frieza.path,
			&new->x, &new->y);
}

void	create_window(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	while (g->map.matrix[i] != NULL)
	{
		j = 0;
		while (g->map.matrix[i][j])
		{
			if (g->map.matrix[i][j] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->map.w, 
					j * 32, i * 32);
			else if (g->map.matrix[i][j] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->coll.img,
					j * 32, i * 32);
			else
				mlx_put_image_to_window(g->mlx, g->win, g->map.t, 
					j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	put_objects(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map.matrix[i])
	{
		j = 0;
		while (g->map.matrix[i][j])
		{
			if (g->map.matrix[i][j] == 'P')
				mlx_put_image_to_window(g->mlx, g->win, g->goku.img,
					j * 32, i * 32);
			if (g->map.matrix[i][j] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->uscita.img,
					j * 32, i * 32);
			if (g->map.matrix[i][j] == 'N')
				mlx_put_image_to_window(g->mlx, g->win, g->frieza.img,
					j * 32, i * 32);
			j++;
		}
		i++;
	}
	ft_printf("Number of moves: %d\n", g->moves);
}



void	start_game(char	*path)
{
	t_game	*new_game;

	new_game = malloc(sizeof(t_game));
	new_game->mlx = mlx_init();
	new_game->win = mlx_new_window(new_game->mlx, 32*23, 32 * 14, "Hello");
	setup(path, new_game);
	create_window(new_game);
	put_objects(new_game);
	mlx_key_hook(new_game->win, move, new_game);
	mlx_loop(new_game->mlx);
}
