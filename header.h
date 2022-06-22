/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:58:59 by lel-khou          #+#    #+#             */
/*   Updated: 2022/06/22 23:03:59 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
#include "mlx/mlx.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#define SIZE 32

typedef	struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		height;
	int		width;
	char	**map;
	void	*img_1;
	void	*img_P;
	void	*img_C;
	void	*img_E;
}	t_game;

void	read_map(char *str, t_game *game);
void	error_check(t_game *game);
int		check_rec(t_game *game);
int		check_walls(t_game *game);
int		check_cep(t_game *game);
void	free_g(t_game *game);
void	load_map(t_game *game);
void	init_img(t_game *game);
void	draw(t_game *game, char c, int i, int j);

#endif