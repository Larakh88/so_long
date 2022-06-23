/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:38:42 by lel-khou          #+#    #+#             */
/*   Updated: 2022/06/23 22:36:54 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_errors(char *str, t_game *game)
{
	ft_putstr_fd(str, 1);
	if (game)
		free(game);
	exit(1);
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