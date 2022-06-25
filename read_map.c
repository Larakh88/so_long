/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 07:23:18 by lel-khou          #+#    #+#             */
/*   Updated: 2022/06/25 23:54:11 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	read_map(char *str, t_game *game)
{
	char	*temp;
	int		i;
	char	buff;
	ssize_t	byte;

	byte = 1;
	i = 0;
	temp = malloc (sizeof(char) * sizeofmap(str, game) + 1);
	if (!temp)
		return (0);
	game->fd = open(str, O_RDONLY);
	if (game->fd == -1)
		ft_error1("Error: Map can't be accessed!\n", game);
	while (byte > 0)
	{
		byte = read(game->fd, &buff, 1);
		if (byte == 0)
			break ;
		temp[i++] = buff;
	}
	temp[i] = '\0';
	if ((!temp[i - 1] && !byte) || byte == -1)
		ft_error1("Error: No Map!\n", game);
	splittemp(temp, game);
	return (0);
}

void	splittemp(char *str, t_game *game)
{
	int	j;

	j = 0;
	game->map = ft_split(str, '\n');
	free (str);
	if (!game->map)
		ft_error1("Error: Malloc Failed!\n", game);
	game->width = ft_strlen(game->map[0]);
	while (game->map[j] != 0)
		j++;
	game->height = j;
}

int	sizeofmap(char *str, t_game *game)
{
	int		fd;
	int		i;
	char	buff;

	i = 0;
	fd = open(str, O_RDONLY);
	if (game->fd == -1)
		ft_error1("Error: Map can't be accessed!\n", game);
	while ((read(fd, &buff, 1)) > 0)
		i++;
	return (i);
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
		ft_error1("Error: Malloc Failed!\n", game);
	}
	j = ft_strlen(str) - 4;
	i = 0;
	while (str[j] != 0)
		ptr[i++] = str[j++];
	ptr[i] = '\0';
	if (ft_strncmp(ptr, ".ber\0", 5) != 0)
	{
		free (ptr);
		ft_error1("Error: Wrong map extension!\n", game);
	}
}
