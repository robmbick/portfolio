/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_put_the_tetra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:00:26 by bnetschu          #+#    #+#             */
/*   Updated: 2019/01/30 17:34:48 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_skip(int *ideal, int ch, int n)
{
	if (ch != 0)
	{
		ideal[1]++;
		if (ideal[1] >= n)
		{
			ideal[0]++;
			ideal[1] = 0;
		}
		return (1);
	}
	return (0);
}

int			help_put_the_tetra(char **square, t_lst *list, int ch, int n)
{
	int		ideal[4];

	ideal[0] = 0;
	ideal[1] = 0;
	while (best_way(square, ideal) > 0)
	{
		if (write_in_sq(square, list->tetra, ideal, list->num + 'A') == 0)
		{
			clear_square(square, list->num + 'A', n);
			ideal[1]++;
			if (ideal[1] == n)
			{
				ideal[0]++;
				ideal[1] = 0;
			}
			continue ;
		}
		if (ft_skip(ideal, ch--, n) == 1)
			continue ;
		return (1);
	}
	return (0);
}

int			help_check(char t, char **square)
{
	int x;
	int y;

	y = 0;
	while (square[y])
	{
		x = 0;
		while (square[y][x])
		{
			if (square[y][x] == t)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int			check_in_tetra(t_lst *list, char **square)
{
	while (list != NULL)
	{
		if (help_check(list->num + 'A', square) == 0)
			return (0);
		list = list->next;
	}
	return (1);
}

void		clear_sq(char **square, char t)
{
	int		x;
	int		y;

	x = 0;
	while (square[x])
	{
		y = 0;
		while (square[y])
		{
			if (square[x][y] == t)
				square[x][y] = '.';
			y++;
		}
		x++;
	}
}
