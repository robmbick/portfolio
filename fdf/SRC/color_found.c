/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_found.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 10:03:54 by bnetschu          #+#    #+#             */
/*   Updated: 2019/03/24 17:19:38 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		help_found_color(char *str, int *i, int color)
{
	char	*s;

	if (str[i[0]] == 'A' || str[i[0]] == 'a')
		color = color + 10 * NONS(i[1]);
	else if (str[i[0]] == 'B' || str[i[0]] == 'b')
		color = color + 11 * NONS(i[1]);
	else if (str[i[0]] == 'C' || str[i[0]] == 'c')
		color = color + 12 * NONS(i[1]);
	else if (str[i[0]] == 'D' || str[i[0]] == 'd')
		color = color + 13 * NONS(i[1]);
	else if (str[i[0]] == 'E' || str[i[0]] == 'e')
		color = color + 14 * NONS(i[1]);
	else if (str[i[0]] == 'F' || str[i[0]] == 'f')
		color = color + 15 * NONS(i[1]);
	else
	{
		s = ft_strsub(&str[i[0]], i[0], 1);
		color += ft_atoi(s) * NONS(i[0]);
		free(s);
	}
	return (color);
}

int				color_found(char *str)
{
	int		i[2];
	int		color;

	color = 0;
	i[0] = 0;
	i[1] = 0;
	while (str[i[0]])
		i[0]++;
	i[0]--;
	while (i[0] >= 0)
	{
		color = help_found_color(str, i, color);
		i[0]--;
		i[1]++;
	}
	return (color);
}

static int		ft_lentab1(char *s, char *k, char c, int i)
{
	while (1)
	{
		if (*s == c)
		{
			i++;
			while (*s == c)
				s++;
		}
		if (*s == '\0')
		{
			if (*k == c && *--s == c)
				i--;
			if (*k != c && *--s != c)
				i++;
			break ;
		}
		s++;
	}
	return (i);
}

int				ft_lentab(char *s, char c)
{
	int		i;
	char	*k;

	k = s;
	i = 0;
	if (*s == c)
	{
		i++;
		while (*s == c)
			s++;
	}
	i = ft_lentab1(s, k, c, i);
	return (i);
}

void			delete_t_in_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
}
