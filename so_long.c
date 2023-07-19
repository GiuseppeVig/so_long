/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:09:04 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/16 12:31:39 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "so_long.h"

/*int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	sprites	new_sprite;
	void	*img;
	void	*dragonball;
	new_sprite.height = 32;
	new_sprite.width = 32;
	new_sprite.path = "./sprites/PC/idle.xpm";

	int		i_x;
	int		i_y;

	i_x = 500 * 2 / 5;
	i_y = 500 * 2 / 5;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hello There");
	img = mlx_xpm_file_to_image(mlx_ptr, new_sprite.path, &new_sprite.height, &new_sprite.width);
	dragonball = mlx_xpm_file_to_image(mlx_ptr, "./sprites/collectibles/dragonball.xpm", &new_sprite.height, &new_sprite.width);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, i_x, i_y);
	mlx_put_image_to_window(mlx_ptr, win_ptr, dragonball, 32, 32);
	mlx_loop(mlx_ptr);
}*/

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Please add a map to run the game");
		exit(0);
	}
	maps	test;

	test.path = argv[1];
	ft_printf("%d\n", check_map_shape(test));
	return (0);
}
