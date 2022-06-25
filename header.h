/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:58:59 by lel-khou          #+#    #+#             */
/*   Updated: 2022/06/25 14:30:58 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define SIZE 32

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		height;
	int		width;
	char	**map;
	void	*img_1;
	void	*img_0;
	void	*img_p;
	void	*img_c;
	void	*img_e;
	int		fd;
	int		c;
	int		p;
	int		e;
	int		x;
	int		y;
	int		moves;
	int		collectibles;
	int		totalc;
}	t_game;

void	check_ex(char *str, t_game *game);
int		read_map(char *str, t_game *game);
int		sizeofmap(char *str, t_game *game);
void	splittemp(char *str, t_game *game);
void	error_check(t_game *game);
int		check_rec(t_game *game);
int		check_walls(t_game *game);
int		check_cep(t_game *game);
int		check_param(t_game *game);
void	load_map(t_game *game);
void	init_img(t_game *game);
void	draw(t_game *game, char c, int i, int j);
int		key_hook(int keycode, t_game *game);
void	moves(t_game *game, int x, int y);
void	ft_error1(char *str, t_game *game);
void	ft_error0(char *str, t_game *game);
void	free_game(t_game *game);
int		destroy_game(t_game *game);

#endif
