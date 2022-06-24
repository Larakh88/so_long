# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 13:59:41 by lel-khou          #+#    #+#              #
#    Updated: 2022/06/23 12:52:53 by lel-khou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g

CFLAGS = -Wall -Werror -Wextra -Imlx

HEADER = header.h

LIBFT = libft.a

LIBS = -L./libft -lft

NAME = so_long

RM = rm -f

SRC = main.c load_map.c read_map.c error_check.c ft_errors.c hooks.c

OBJS = $(SRC:.c=.o)

all		: $(LIBFT) $(NAME)

$(LIBFT) :
	@make -C libft

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
clean: 
	$(RM) $(OBJS)
	@make clean -C libft

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft
	
re:	fclean all


