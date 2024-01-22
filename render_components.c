/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_components.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:49:29 by gvigilan          #+#    #+#             */
/*   Updated: 2024/01/22 22:19:54 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup(char *path, t_game *new)
{
	new->matrix = read_map(path);
	new->map.matrix = read_map(path);
	new->counter = num_of_collectables(new->map.matrix);
	new->goku.path = "./sprites/PC/idle.xpm";
	new->goku.tp.path = "./sprites/PC/idle.xpm";
	new->frieza.path = "./sprites/NPC/idle.xpm";
	new->coll.path = "./sprites/balls/ball.xpm";
	new->uscita.path = "./sprites/exit/exit.xpm";
	new->map.w_path = "./sprites/terrain/wall.xpm";
	new->map.t_path = "./sprites/terrain/floor.xpm";
	new->goku.pos = start_pos(new->map);
	new->frieza.pos = start_pos_enemy(new->map);
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
	new->goku.tp.img = mlx_xpm_file_to_image(new->mlx, new->goku.tp.path,
			&new->x, &new->y);
}

void	create_window(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	while (g->matrix[i] != NULL)
	{
		j = 0;
		while (j < (int)ft_strlen(g->matrix[i]))
		{
			if (g->matrix[i][j] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->map.w,
					j * 32, i * 32);
			else if (g->matrix[i][j] == 'C')
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

void	put_objects(t_game *g, int print)
{
	int	i;
	int	j;

	i = 0;
	while (g->matrix[i])
	{
		j = 0;
		while (g->matrix[i][j])
		{
			if (g->matrix[i][j] == 'P')
				mlx_put_image_to_window(g->mlx, g->win, g->goku.img,
					j * 32, i * 32);
			if (g->matrix[i][j] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->uscita.img,
					j * 32, i * 32);
			if (g->matrix[i][j] == 'N')
				mlx_put_image_to_window(g->mlx, g->win, g->frieza.img,
					j * 32, i * 32);
			if (g->matrix[i][j] == 'A')
				mlx_put_image_to_window(g->mlx, g->win, g->goku.tp.img,
					j * 32, i * 32);
			j++;
		}
		i++;
	}
	if (print)
		ft_printf("Number of moves: %d\n", g->moves);
}

void	start_game(char	*path)
{
	t_game	*new_game;

	new_game = malloc(sizeof(t_game));
	new_game->mlx = mlx_init();
	setup(path, new_game);
	new_game->win = mlx_new_window(new_game->mlx, 32 * ml(new_game),
			32 * mh(new_game), "so_long");
	if (!run_full_check(new_game))
	{
		ft_printf("ERROR, Invalid Map");
		exit(1);
	}
	create_window(new_game);
	put_objects(new_game, 1);
	//mlx_loop_hook(new_game->mlx, move_around, new_game);
	mlx_key_hook(new_game->win, move, new_game);
	mlx_loop_hook(new_game, adjust_status, new_game);
	mlx_loop(new_game->mlx);
}
