/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:09:04 by gvigilan          #+#    #+#             */
/*   Updated: 2024/01/23 02:27:39 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vec2D	start_pos_enemy(t_maps map)
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
			if (map.matrix[x][y] == 'N')
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

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (argc == 3 && ft_atoi(argv[2]))
			start_game(argv[1], 1);
		else
			start_game(argv[1], 0);
	}
	else
	{
		ft_printf("Hai dimenticato la mappa coglione");
		exit(1);
	}
	return (0);
}
