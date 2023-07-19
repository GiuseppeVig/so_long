/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:38:28 by gvigilan          #+#    #+#             */
/*   Updated: 2023/04/09 19:38:28 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "../libft/libft.h"
# define BUFFER_SIZE 1000;

char	*get_next_line_bonus(int fd);
char	*read_line(int fd, char *c);
char    *has_new_line(char *s);
char	*ft_join(char *s1, char *s2);
char	*get_output(char *total);
char	*reset_line(char *str);

#endif