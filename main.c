/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:59:09 by lel-khou          #+#    #+#             */
/*   Updated: 2022/06/19 22:44:12 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_game    *game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_putstr_fd("Malloc failed\n", 1);
	if (argc == 2)
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
		fd = open(argv[1], O_RDONLY);
		while ((byte = read(fd, &buff, 1)) > 0)
			temp[i++] = buff;
		if((!temp[i - 1] && !byte) || byte == -1)
		{
			free (temp);
			return (0);
		}
		temp[i] = '\0';
		game->map = ft_split(temp, '\n');
		game->width = ft_strlen(game->map[0]) * 32;
		printf("width%d\n", game->width);
		while (game->map[j] != 0)
			j++;
		game->height = j * 32;
		printf("%d\n", game->height);
		load_map(game);
		mlx_loop(game->mlx_ptr);
	}
	else
    	ft_putstr_fd("Error: Wrong number of arguments.", 1); 
}