/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:23:16 by lel-khou          #+#    #+#             */
/*   Updated: 2022/06/25 13:43:33 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error_check(t_game *game)
{
	if (check_rec(game) == 0)
		ft_error1("Error: Map is not rectangular!\n", game);
	if (check_walls(game) == 0)
		ft_error1("Error: Map is not surrounded by walls!\n", game);
	if (check_cep(game) == 0)
		ft_error1("Error: Map has wrong nb of C, E or P!\n", game);
	if (check_param(game) == 0)
		ft_error1("Error: Map has extra parameters!\n", game);
}

int	check_rec(t_game *game)
{
	int	i;

	i = 0;
	while (i < (game->height - 1))
	{
		if (ft_strlen(game->map[i]) == ft_strlen(game->map[i + 1]))
			i++;
		else
			break ;
	}
	i++;
	if (i != (game->height) || i == (game->width))
		return (0);
	else
		return (1);
}

int	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i] != 0)
	{
		if (game->map[0][i] == '1' && game->map[game->height - 1][i] == '1')
			i++;
		else
			return (0);
	}
	i = 0;
	while (i < (game->height))
	{
		if (game->map[i][0] == '1' && game->map[i][game->width - 1] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_cep(t_game *game)
{
	int	i;

	i = 0;
	while (i < (game->height))
	{
		if (ft_strchr(game->map[i], 'C') != 0)
			game->c++;
		if (ft_strchr(game->map[i], 'P') != 0)
			game->p++;
		if (ft_strchr(game->map[i], 'E') != 0)
			game->e++;
		i++;
	}
	if ((game->c > 0 && game->p > 0 && game->e > 0) && game->p == 1)
		return (1);
	else
		return (0);
}

int	check_param(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != 0)
	{
		j = 0;
		while (game->map[i][j] != 0)
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1' \
			&& game->map[i][j] != 'E' && game->map[i][j] != 'C' \
			&& game->map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
