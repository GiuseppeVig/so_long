/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:56:59 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/04 14:50:44 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	space
{
    int position_x;
    int position_y;    
}				vec2D;

typedef struct	pc
{
	vec2D	position;
	char	sprite;
}				player;

#endif