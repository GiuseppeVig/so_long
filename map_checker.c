/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:13:50 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/11 14:31:43 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_shape(char *location, char *name)
{
	int	fd;
	int	len;
	int	compare;
	
	fd = open(ft_strjoin(location, name));
	len = ft_strlen(get_next_line_bonus(fd));
	compare = ft_strlen(get_next_line_bonus(fd));
	while (compare)
	{
		if (compare != len)
		{
			ft_printf("Invalid map Format");	
			return (0);
		}
		compare = ft_strlen(get_next_line_bonus(fd));
	}
	close(fd);
	return (1);
}

int	open_walls(char *location)
{
	char	**map;
		
}
