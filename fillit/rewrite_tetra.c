/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite_tetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 11:49:06 by okherson          #+#    #+#             */
/*   Updated: 2019/01/30 16:46:21 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	rewriting_tetra(t_lst *list)
{
	int	c[4];

	c[0] = -1;
	c[2] = 0;
	while (++c[0] < 4)
	{
		if (list->matrix[c[0]][0] == '#' || list->matrix[c[0]][1] == '#' ||
		list->matrix[c[0]][2] == '#' || list->matrix[c[0]][3] == '#')
		{
			c[1] = 0;
			c[3] = 0;
			while (c[1] < 4)
			{
				if ((list->matrix[0][c[1]] == '#' || list->matrix[1][c[1]]
				== '#' || list->matrix[2][c[1]] == '#' || list->matrix[3][c[1]]
				== '#') && (c[3] < list->l))
				{
					list->tetra[c[2]][c[3]] = list->matrix[c[0]][c[1]];
					c[3]++;
				}
				c[1]++;
			}
			c[2]++;
		}
	}
}

void	mem_tetra(t_lst *list)
{
	int	n;

	list->tetra = (char **)malloc(sizeof(char *) * (list->h + 1));
	n = 0;
	while (n < list->h)
	{
		list->tetra[n] = ft_memalloc((unsigned char)list->l + 1);
		ft_bzero(list->tetra[n], (unsigned char)list->l + 1);
		n++;
	}
	list->tetra[list->h] = NULL;
	rewriting_tetra(list);
}

void	rewrite_tetra(t_lst *list)
{
	int	l_tetr;
	int	h_tetr;
	int	a;

	a = 0;
	l_tetr = 0;
	h_tetr = 0;
	while (a < 4)
	{
		if (list->matrix[0][a] == '#' || list->matrix[1][a] == '#' ||
		list->matrix[2][a] == '#' || list->matrix[3][a] == '#')
			l_tetr++;
		a++;
	}
	list->l = l_tetr;
	a = 0;
	while (a < 4)
	{
		if (list->matrix[a][0] == '#' || list->matrix[a][1] == '#' ||
		list->matrix[a][2] == '#' || list->matrix[a][3] == '#')
			h_tetr++;
		a++;
	}
	list->h = h_tetr;
	mem_tetra(list);
}
