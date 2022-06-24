/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:23:16 by lel-khou          #+#    #+#             */
/*   Updated: 2022/06/24 22:54:54 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error_check(t_game *game)
{
	if (check_rec(game) == 0)
		ft_errors("Error: Map is not rectangular!\n", game);
	if (check_walls(game) == 0)
		ft_errors("Error: Map is not surrounded by walls!\n", game);
	if (check_cep(game) == 0)
		ft_errors("Error: Map is missing a C or E or P\n", game);
}

int		check_rec(t_game *game)
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

int		check_walls(t_game *game)
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
	//Check if we need to check for extra Player or for any extra character in the map, if not, remove the last else if
	while (i < (game->height))
	{
		if (ft_strchr(game->map[i], 'C') != 0)
			c++;
		if (ft_strchr(game->map[i], 'P') != 0)
			p++;
		if (ft_strchr(game->map[i], 'E') != 0)
			e++;
		else if (ft_strchr(game->map[i], '0') == 0 && ft_strchr(game->map[i], '1') == 0)
			return (0);
		i++;
	}
	if (c > 0 && p > 0 && e > 0)
		return (1);
	else
		return (0);
}

void	check_ex(char *str, t_game *game)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = malloc (sizeof(char) * 5);
	if (!ptr)
	{
		free (ptr);
		ft_errors("Malloc failed\n", game);
	}
	j = ft_strlen(str) - 4;
	i = 0;

	while (str[j] != 0)
		ptr[i++] = str[j++];
	ptr[i] = '\0';
	if (ft_strncmp(ptr, ".ber\0", 5) != 0)
		ft_errors("Error: Wrong map extension\n", game);
	free (ptr);
}