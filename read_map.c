/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 07:23:18 by lel-khou          #+#    #+#             */
/*   Updated: 2022/06/23 23:12:51 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
		
void	read_map(char *str, t_game *game)
{
	int		fd;
    char	buff;
    ssize_t	byte;
    char	*temp = malloc(100);
    int		i;
	int		j;

	byte = 1;
	i = 0;
	j = 0;
	fd = open(str, O_RDONLY);
	while ((byte = read(fd, &buff, 1)) > 0)
		temp[i++] = buff;
	if((!temp[i - 1] && !byte) || byte == -1)
		free (temp);
	temp[i] = '\0';
	game->map = ft_split(temp, '\n');
	free (temp);
	game->width = ft_strlen(game->map[0]);
	while (game->map[j] != 0)
		j++;
	game->height = j;
}