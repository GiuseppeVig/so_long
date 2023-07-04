/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:35:11 by gvigilan          #+#    #+#             */
/*   Updated: 2023/07/04 15:10:29 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	int		i_x;
	int		i_y;

	i_x = 500 * 2 / 5;
	i_y = 500 * 2 / 5;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hello There");
	mlx_string_put(mlx_ptr, win_ptr, i_x, i_y, 0xccccff, "Hello World");
	mlx_loop(mlx_ptr);
}
