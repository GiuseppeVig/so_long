/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:56:35 by gvigilan          #+#    #+#             */
/*   Updated: 2023/10/13 17:09:36 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_intruder(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->matrix[i])
	{
		j = 0;
		while (g->matrix[i][j])
		{
			if (g->matrix[i][j] != '1' ||
				g->matrix[i][j] != '0' ||
				g->matrix[i][j] != 'P' ||
				g->matrix[i][j] != 'C' ||
				g->matrix[i][j] != 'N' ||
				g->matrix[i][j] != 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	run_full_check(t_game *g)
{
	if (!check_map_shape(g->percorso))
		return (0);
	if (!open_walls(g->matrix))
		return (0);
	if (!check_p_and_e(g->matrix))
		return (0);
	if (!pathfind(g))
		return (0);
	return (1);
}

int	ml(t_game *g)
{
	return (ft_strlen(g->matrix[1]));
}

int	mh(t_game *g)
{
	int	i;

	i = 0;
	while (g->matrix[i])
		i++;
	return (i);
}
