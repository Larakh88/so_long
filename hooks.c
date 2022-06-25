/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:51:07 by lel-khou          #+#    #+#             */
/*   Updated: 2022/06/25 14:01:43 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	key_hook(int keycode, t_game *game)
{	
	int	i;
	int	j;

	i = game->x;
	j = game->y;
	if (keycode == 53)
		destroy_game(game);
	if (keycode == 2)
		i++;
	if (keycode == 1)
		j++;
	if (keycode == 0)
		i--;
	if (keycode == 13)
		j--;
	moves(game, i, j);
	return (0);
}

void	moves(t_game *game, int i, int j)
{
	if (game->map[j][i] == 'C' || game->map[j][i] == '0')
	{
		if (game->map[j][i] == 'C')
			game->collectibles++;
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_0, \
		game->x * SIZE, game->y * SIZE);
		game->map[game->y][game->x] = '0';
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_p, \
		i * SIZE, j * SIZE);
		game->x = i;
		game->y = j;
		game->map[j][i] = 'P';
		game->moves++;
		ft_putstr_fd("Steps Taken: ", 1);
		ft_putnbr_fd(game->moves, 1);
		ft_putstr_fd("\n", 1);
	}
	if (game->map[j][i] == 'E')
	{
		if (game->totalc == game->collectibles)
			ft_error0("Game won!\n", game);
	}
}

int	destroy_game(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img_1);
	mlx_destroy_image(game->mlx_ptr, game->img_c);
	mlx_destroy_image(game->mlx_ptr, game->img_e);
	mlx_destroy_image(game->mlx_ptr, game->img_p);
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	free(game);
	ft_putstr_fd("Game was closed!\n", 1);
	exit(0);
	return (0);
}
