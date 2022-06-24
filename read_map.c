/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 07:23:18 by lel-khou          #+#    #+#             */
/*   Updated: 2022/06/24 22:58:06 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
		
//Long function check how to make it shorter
void	read_map(char *str, t_game *game)
{
	int		fd;
    char	buff;
    ssize_t	byte;
    char	*temp;
    int		i;
	int		j;

	byte = 1;
	i = 0;
	j = 0;
	temp = malloc (sizeof(char) * sizeofmap(str) + 1);
	if (!temp)
		free (temp);
	fd = open(str, O_RDONLY);
	while ((byte = read(fd, &buff, 1)) > 0)
		temp[i++] = buff;
	if((!temp[i - 1] && !byte) || byte == -1)
	{
		ft_errors("Error: No Map\n", game);
		free (temp);
	}
	temp[i] = '\0';
	game->map = ft_split(temp, '\n');
	free (temp);
	game->width = ft_strlen(game->map[0]);
	while (game->map[j] != 0)
		j++;
	game->height = j;
}

{
	int		fd;
	int		i;
	char	buff;

	i = 0;
	fd = open(str, O_RDONLY);
	while ((read(fd, &buff, 1)) > 0)
		i++;
	return (i);
}