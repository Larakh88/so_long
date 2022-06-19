/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:13:04 by lel-khou          #+#    #+#             */
/*   Updated: 2022/06/19 22:44:19 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	load_map(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->width, game->height, "game");
}