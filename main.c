/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:59:09 by lel-khou          #+#    #+#             */
/*   Updated: 2022/06/25 13:47:57 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char **argv)
{
	t_game    *game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error1("Error: Malloc Failed!\n", game);
	if (argc == 2)
	{
		if (open(argv[1], O_DIRECTORY) != -1)
			ft_error1("Error: Map file is a directory!\n", game);
		check_ex(argv[1], game);
		read_map(argv[1], game);
		error_check(game);
		load_map(game);
		mlx_key_hook(game->mlx_win, key_hook, game);
		mlx_hook(game->mlx_win, 17, 0, destroy_game, game);
		mlx_loop(game->mlx_ptr);
	}
	else
    	ft_putstr_fd("Error: Wrong number of arguments!\n", 1); 
}