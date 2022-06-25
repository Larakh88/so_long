/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:38:42 by lel-khou          #+#    #+#             */
/*   Updated: 2022/06/25 23:54:14 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_error1(char *str, t_game *game)
{
	ft_putstr_fd(str, 1);
	if (game)
		free_game(game);
	exit(1);
}

void	ft_error0(char *str, t_game *game)
{
	ft_putstr_fd(str, 1);
	if (game)
		free_game(game);
	exit(0);
}

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (i < game->height)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	free(game);
}
