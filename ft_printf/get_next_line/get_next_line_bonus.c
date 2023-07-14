/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:38:19 by gvigilan          #+#    #+#             */
/*   Updated: 2023/04/09 19:38:19 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char *c)
{
	char	*str;
	int		i;

	str = (char *)malloc(BUFFER_SIZE + 1);
	if (!str)
		return (0);
	i = 1;
	while (!has_new_line(c) && i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			return (0);
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

char	*get_next_line_bonus(int fd)
{
	static char	*line[4096];
	char		*output;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line[fd] = read_line(fd, line[fd]);
	if (!line[fd])
		return (0);
	output = get_output(line[fd]);
	line[fd] = reset_line(line[fd]);
	return (output);
}
