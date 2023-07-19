/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:13:50 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/16 13:31:45 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// char	read_map(char *location)
// {
	
// }

int	check_map_shape(maps m)
{
	int	fd;
	int	len;
	int	compare;
	
	fd = open(m.path, O_RDONLY);
	len = ft_strlen(get_next_line(fd));
	compare = ft_strlen(get_next_line(fd));
	while (compare)
	{
		if (compare != len)
		{
			ft_printf("Invalid map Format");	
			return (0);
		}
		compare = ft_strlen(get_next_line(fd));
	}
	close(fd);
	return (1);
}

// int	open_walls(char *location)
// {
// 	char	**map;

// 	map = read_map(location);
// }
