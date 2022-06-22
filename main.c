/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:59:09 by lel-khou          #+#    #+#             */
/*   Updated: 2022/06/22 13:57:18 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_game    *game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_putstr_fd("Malloc failed\n", 1);
	if (argc == 2)
	{
		read_map(argv[1], game);
		load_map(game);
		mlx_loop(game->mlx_ptr);
	}
	else
    	ft_putstr_fd("Error: Wrong number of arguments.", 1); 
}