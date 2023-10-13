/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:38:37 by gvigilan          #+#    #+#             */
/*   Updated: 2023/04/09 19:38:37 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_output(char *total)
{
	size_t	i;
	char	*out;

	i = 0;
	while (total[i] && total[i] != '\n')
		i ++;
	out = (char *)malloc(sizeof(char) * i + 2);
	i = 0;
	while (total[i] && total[i] != '\n')
	{
		out[i] = total[i];
		i ++;
	}
	if (total[i] == '\n')
		out [i++] = '\n';
	out[i] = '\0';
	return (out);
}

char	*has_new_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == ('\n'))
			return ((char *)&s[i]);
		i ++;
	}
	return (0);
}

char	*ft_join(char *s1, char *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	joined = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
		return (0);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			joined[i] = s1[i];
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = '\0';
	free(s1);
	return (joined);
}

char	*reset_line(char *str)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	temp = (char *)malloc(ft_strlen(str) - i + 1);
	if (!temp)
		return (0);
	j = 0;
	i ++;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	free(str);
	return (temp);
}
