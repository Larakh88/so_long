/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:13:04 by lel-khou          #+#    #+#             */
/*   Updated: 2022/06/24 21:29:40 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	load_map(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->width * SIZE, \
	game->height * SIZE, "Mario");
	init_img(game);
	while (i < game->height) 
	{
		j = 0;
		while (j < game->width)
		{
			c = game->map[i][j];
			draw(game, c, i, j);
			j++;
		}
		i++;
	}
}

void	init_img(t_game *game)
{
	int		x;
	int		y;

	game->img_1 = mlx_xpm_file_to_image(game->mlx_ptr, "./img/wall.xpm", &x, &y);
	game->img_C = mlx_xpm_file_to_image(game->mlx_ptr, "./img/colct.xpm", &x, &y);
	game->img_P = mlx_xpm_file_to_image(game->mlx_ptr, "./img/playr.xpm", &x, &y);
	game->img_E = mlx_xpm_file_to_image(game->mlx_ptr, "./img/exit.xpm", &x, &y);
	game->img_0 = mlx_xpm_file_to_image(game->mlx_ptr, "./img/empty.xpm", &x, &y);
}

void	draw(t_game *game, char c, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_1, \
		j * SIZE, i * SIZE);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_E, \
		j * SIZE, i * SIZE);
	if (c == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_C, \
		j * SIZE, i * SIZE);
		game->totalc++;
	}
	if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_P, \
		j * SIZE, i * SIZE);
		game->x = j;
		game->y = i;
	}
}