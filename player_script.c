/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_script.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:50:55 by gvigilan          #+#    #+#             */
/*   Updated: 2023/10/10 21:01:51 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vec2D start_pos(t_maps map)
{
    t_vec2D start;
    int     x;
    int     y;

    x = 0;
    start.x = 0;
    start.y = 0;
    while (map.matrix[x])
    {
        y = 0;
        while (map.matrix[x][y])
        {
            if (map.matrix[x][y] == 'P')
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

// void    move_vertical(t_game *g)
// {
//     t_vec2D pos;

//     pos = g->map.goku.pos;
//     if (press_UP())
//     {
//         if (g->map.matrix[pos.x + 1][pos.y] != '1')
//         {
//             g->map.goku.pos.x += 1;
//             if (g->map.matrix[pos.x + 1][pos.y] == 'C')
//                 g->counter--;
//             g->moves++; 
//         }
//     }
//     if (press_DOWN())
//     {
//         if (g->map.matrix[pos.x + 1][pos.y] != '1')
//         {
//             g->map.goku.pos.x -= 1;
//             if (g->map.matrix[pos.x - 1][pos.y] == 'C')
//                 g->counter--;
//             g->moves++; 
//         }
//     }
// }

// void    move_horizonta(t_game *g)
// {
//     t_vec2D pos;

//     pos = g->map.goku.pos;
//     if (press_RIGHT())
//     {
//         if (g->map.matrix[pos.x][pos.y + 1] != '1')
//         {
//             g->map.goku.pos.y += 1;
//             if (g->map.matrix[pos.x][pos.y + 1] == 'C')
//                 g->counter--;
//             g->moves++; 
//         }
//     }
//     if (press_LEFT())
//     {
//         if (g->map.matrix[pos.x][pos.y - 1] != '1')
//         {
//             g->map.goku.pos.y -= 1;
//             if (g->map.matrix[pos.x][pos.y - 1] == 'C')
//                 g->counter--;
//             g->moves++; 
//         }
//     }
// }

// void    adjust_sprite(t_game *g)
// {

// }
