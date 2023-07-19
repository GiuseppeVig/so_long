/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:38:57 by gvigilan          #+#    #+#             */
/*   Updated: 2023/04/09 19:38:57 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *c)
{
	char	*str;
	int		i;

	str = (char *)malloc(1000 + 1);
	if (!str)
		return (0);
	i = 1;
	while (!has_new_line(c) && i != 0)
	{
		i = read(fd, str, 1000);
		if (i == -1)
		{
			free(str);
			return (c);
		}
		str[i] = '\0';
		c = ft_join(c, str);
	}
	free(str);
	if (c[0] == '\0')
	{
		free(c);
		return (0);
	}
	return (c);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*output;

	if (fd < 0 || 1000 <= 0)
		return (0);
	line = read_line(fd, line);
	if (!line)
	{
		free(line);
		return (0);
	}
	output = get_output(line);
	line = reset_line(line);
	return (output);
}
