/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:09:04 by gvigilan          #+#    #+#             */
/*   Updated: 2023/10/13 17:14:20 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		start_game(argv[1]);
	}
	else
	{
		ft_printf("Hai dimenticato la mappa coglione");
		exit(1);
	}
	return (0);
}
