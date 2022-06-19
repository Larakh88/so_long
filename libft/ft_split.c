/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 09:57:23 by lel-khou          #+#    #+#             */
/*   Updated: 2021/11/22 08:57:53 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] == c)
			i++;
		if (s[i] == 0)
			break ;
		if (s[i + 1] == c || s[i + 1] == 0)
			j++;
		i++;
	}
	return (j);
}

static size_t	ft_start(const char *s, char c)
{
	size_t	start;

	start = 0;
	while (s != 0)
	{
		if (*s == c && *s != 0)
		{
			start++;
			s++;
		}
		else
			break ;
	}
	return (start);
}

static size_t	ft_end(const char *s, char c)
{
	size_t	end;

	end = 0;
	while (s != 0)
	{
		if (*s != c && *s != 0)
		{	
			end++;
			s++;
		}
		else
			break ;
	}
	return (end);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	j;
	size_t	k;
	char	*d;

	i = 0;
	j = 0;
	k = 0;
	d = (char *)s;
	if (!s)
		return (0);
	ptr = malloc(sizeof(char *) * ft_count(s, c) + 1);
	if (!ptr)
		return (0);
	while (i < ft_count(s, c))
	{
		j = ft_start(d, c);
		k = ft_end(d + j, c);
		ptr[i] = ft_substr(d, j, k);
		d = d + j + k;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
