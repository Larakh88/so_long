/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:58:59 by lel-khou          #+#    #+#             */
/*   Updated: 2022/06/19 22:44:15 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include "mlx/mlx.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef	struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		height;
	int		width;
	char	**map;
}	t_game;

void	load_map(t_game *game);

#endif