/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:13:50 by gvigilan          #+#    #+#             */
/*   Updated: 2023/09/13 15:09:10 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(maps m)
{
	int		fd;
	char	*map;
	char	*tmp;
	char	**matrix;
	
	fd = open(m.path, O_RDONLY);
	map = get_next_line_bonus(fd);
	tmp = get_next_line_bonus(fd);
	while (ft_strlen(tmp) != 0)
	{
		map = ft_strjoin(map, tmp);
		tmp = get_next_line_bonus(fd);
	}
	close(fd);
	matrix = ft_split(map, '\n');
	return (matrix);
}

int	check_map_shape(maps m)
{
	int	fd;
	int	len;
	int	compare;
	
	fd = open(m.path, O_RDONLY);
	len = ft_strlen(get_next_line_bonus(fd));
	compare = ft_strlen(get_next_line_bonus(fd));
	while (compare != 0)
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

int	open_walls_horizontal(maps m)
{
	char	**map;
	int		i;
	int		j;

	map = read_map(m);
	i = 0;
	while (map[i] != NULL)
	{
		ft_printf("%s\n", map[i]);
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || map[i + 1] == NULL)
			{
				if (map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	open_walls_vertical(maps m)
{
	char	**map;
	int		i;
	int		j;

	map = read_map(m);
	i = 0;
	while (map[i] != NULL)
	{
		ft_printf("%s\n", map[i]);
		j = 0;
		while (map[i][j])
		{
			if(j == 0 || j == ((int)ft_strlen(map[i]) - 1))
			{
				if (map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
