/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 10:12:12 by bnetschu          #+#    #+#             */
/*   Updated: 2019/03/29 11:42:07 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				check_tab(char *tab)
{
	int i;
	int k;

	k = 0;
	i = 0;
	i = help_ch_tab(i, tab);
	if (tab[i] == '\0')
		return (0);
	if (i == 0)
		return (-1);
	else if (tab[i] == ',' && tab[i + 1] == '0' && tab[i + 2] == 'x')
	{
		i += 3;
		if (tab[i] == '\0')
			return (0);
		while (tab[i])
		{
			if ((check_tab_k(tab, i, &k)) == -1)
				return (k);
			i++;
		}
		return (1);
	}
	return (-1);
}

void			iso(t_fdf **fdf, float angl)
{
	int i;
	int j;

	j = 0;
	while (j != fdf[0][0].y_max)
	{
		i = 0;
		while (i != fdf[0][0].x_max)
		{
			fdf[j][i].x = (fdf[j][i].d_x + fdf[j][i].d_y) * cos(angl);
			fdf[j][i].y = (fdf[j][i].d_x - fdf[j][i].d_y) *
								sin(angl) - fdf[j][i].d_z;
			i++;
		}
		j++;
	}
}

static void		for_centr(t_fdf **fdf, int x, int y)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while (j != fdf[0][0].y_max)
	{
		i = 0;
		while (i != fdf[0][0].x_max)
		{
			fdf[j][i].x -= x;
			fdf[j][i].y += y;
			i++;
		}
		j++;
	}
}

static int		centr_help(int *xy_fdf, t_fdf **fdf, int i, int j)
{
	int y;

	y = 0;
	while ((xy_fdf[1] != fdf[j][i].d_y))
	{
		if ((xy_fdf[1]) < fdf[j][i].d_y)
			xy_fdf[1]++;
		else if ((xy_fdf[1]) > fdf[j][i].d_y)
			xy_fdf[1]--;
		y++;
	}
	return (y);
}

void			centr(t_fdf **fdf)
{
	int	i;
	int j;
	int	x;
	int y;
	int xy_fdf[2];

	x = 0;
	i = fdf[0][0].x_max / 2;
	j = fdf[0][0].y_max / 2;
	xy_fdf[0] = fdf[j][i].x;
	while ((xy_fdf[0] != fdf[j][i].d_x))
	{
		if ((xy_fdf[0]) < fdf[j][i].d_x)
			xy_fdf[0]++;
		else if ((xy_fdf[0]) > fdf[j][i].d_x)
			xy_fdf[0]--;
		x++;
	}
	xy_fdf[1] = fdf[j][i].y;
	y = centr_help(xy_fdf, fdf, i, j);
	for_centr(fdf, x, y);
}
