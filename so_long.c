/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:09:04 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/14 15:32:26 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "so_long.h"

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	sprites	new_sprite;
	void	*img;
	new_sprite.height = 100;
	new_sprite.width = 100;
	new_sprite.path = "./sprites/PC/idle.xpm";

	int		i_x;
	int		i_y;

	i_x = 500 * 2 / 5;
	i_y = 500 * 2 / 5;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hello There");
	img = mlx_xpm_file_to_image(mlx_ptr, new_sprite.path, &new_sprite.height, &new_sprite.width);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, i_x, i_y);
	mlx_loop(mlx_ptr);
}
