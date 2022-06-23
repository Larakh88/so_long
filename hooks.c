/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:51:07 by lel-khou          #+#    #+#             */
/*   Updated: 2022/06/23 22:36:50 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		key_hook(int keycode, t_game *game)
{	
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (keycode == 53)
		destroy_game(game);
	if (keycode == 2)
		x++;
	if (keycode == 1)
		y++;
	if (keycode == 0)
		x--;
	if (keycode == 13)
		y--;
	moves(game, x, y);
	return (0);
}

void	moves(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C' || game->map[y][x] == '0')
	{
		if (game->map[y][x] == 'C')
			game->collectibles++;
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_0, \
		game->x * SIZE, game->y * SIZE);
		game->map[game->y][game->x] = '0';
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_P, \
		x * SIZE, y * SIZE);
		game->x = x;
		game->y = y;
		game->map[y][x] = 'P';
		game->moves++;
		ft_putstr_fd("Steps Taken: ", 1);
		ft_putnbr_fd(game->moves, 1);
		ft_putstr_fd("\n", 1);
	}
	if (game->map[y][x] == 'E')
	{
		if (game->totalc == game->collectibles)
			ft_errors("Game won!", game);
	}
}

int		destroy_game(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img_1);
	mlx_destroy_image(game->mlx_ptr, game->img_C);
	mlx_destroy_image(game->mlx_ptr, game->img_E);
	mlx_destroy_image(game->mlx_ptr, game->img_P);
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	free(game);
	ft_putstr_fd("Game was closed\n", 1);
	exit(0);
	return (0);
}