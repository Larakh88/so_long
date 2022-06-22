/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:23:16 by lel-khou          #+#    #+#             */
/*   Updated: 2022/06/22 23:05:05 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error_check(t_game *game)
{
	if (check_rec(game) == 0)
	{
		ft_putstr_fd("Error: Map is not rectangular!\n", 1);
		if (game)
			free(game);
		exit(1);
	}
	if (check_walls(game) == 0)
	{
		ft_putstr_fd("Error: Map is not surrounded by walls!\n", 1);
		if (game)
			free(game);
		exit (1);
	}
	if (check_cep(game) == 0)
	{
		ft_putstr_fd("Error: Map is missing a C or E or P\n", 1);
		if (game)
			free(game);
		exit (1);
	}
}
/* check if this is needed or free is enough
void	free_g(t_game *game)
{
	int	i;

	i = 0;
	if (game->map[0] != 0)
	{
		while (i < (game->height / SIZE))
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	free(game);
}*/

int		check_rec(t_game *game)
{
	int	i;

	i = 0;
	while (i < (game->height / SIZE - 1))
	{
		if (ft_strlen(game->map[i]) == ft_strlen(game->map[i + 1]))
			i++;
		else
			break ;
	}
	i++;
	if (i != (game->height / SIZE) || i == (game->width / SIZE))
		return (0);
	else
		return (1);	
}

int		check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i] != 0)
	{
		if (game->map[0][i] == '1' && game->map[game->height / SIZE - 1][i] == '1')
			i++;
		else
			return (0);
	}
	i = 0;
	while (i < (game->height / SIZE))
	{
		if (game->map[i][0] == '1' && game->map[i][game->width / SIZE - 1] == '1')
			i++;
		else
			return(0);
	}
	return (1);
}

int		check_cep(t_game *game)
{
	int	i;
	int c;
	int	p;
	int	e;

	i = 0;
	c = 0;
	p = 0;
	e = 0;
	while (i < (game->height / SIZE))
	{
		if (ft_strchr(game->map[i], 'C') != 0)
			c++;
		if (ft_strchr(game->map[i], 'P') != 0)
			p++;
		if (ft_strchr(game->map[i], 'E') != 0)
			e++;
		i++;
	}
	if (c > 0 && p > 0 && e > 0)
		return (1);
	else
		return (0);
}