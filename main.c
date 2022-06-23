/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:59:09 by lel-khou          #+#    #+#             */
/*   Updated: 2022/06/23 13:46:30 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_game    *game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_putstr_fd("Malloc failed\n", 1);
		free (game);
		exit (1);
	}
	if (argc == 2)
	{
		if (open(argv[1], O_DIRECTORY) != -1)
			ft_errors("Error: Map file is a directory!", game);
		check_ex(argv[1], game);
		read_map(argv[1], game);
		error_check(game);
		load_map(game);
		mlx_key_hook(game->mlx_win, key_hook, game);
		mlx_hook(game->mlx_win, 17, 0, destroy_game, game);
		mlx_loop(game->mlx_ptr);
	}
	else
    	ft_putstr_fd("Error: Wrong number of arguments.", 1); 
}