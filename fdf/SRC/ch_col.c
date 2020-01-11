/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_col.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:50:39 by bnetschu          #+#    #+#             */
/*   Updated: 2019/03/29 11:42:46 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		iter_col(int *col)
{
	int r;

	r = *col;
	if (*col < 4 && *col >= 0)
		return (*col);
	else if (*col > 4)
	{
		while (r > 4)
			r -= 5;
	}
	else
	{
		while (r < 0)
			r += 5;
	}
	return (r);
}

void			ch_col(t_fdf **fdf, t_mlxptr *mlx, int *col, int it)
{
	int i;
	int j;
	int color[5];
	int i_col;

	i_col = iter_col(col);
	color[0] = 255;
	color[1] = 65025;
	color[2] = 10587125;
	color[3] = 16581375;
	color[4] = 16777215;
	j = 0;
	while (j != fdf[0][0].y_max)
	{
		i = 0;
		while (i != fdf[0][0].x_max)
		{
			fdf[j][i].color = color[i_col];
			i++;
		}
		j++;
	}
	col[0] += it;
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	connect_line(fdf, mlx);
}

void			isos(t_fdf **fdf, float angl)
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

int				check_tab_k(char *tab, int i, int *k)
{
	if (*k > 5)
	{
		k[0] = 0;
		return (-1);
	}
	if ((tab[i] < 65 || tab[i] > 70) && (tab[i] < 48
				|| tab[i] > 57) && (tab[i] < 97 || tab[i] > 102))
	{
		*k = -1;
		return (-1);
	}
	k[0]++;
	return (1);
}

int				help_ch_tab(int i, char *tab)
{
	if (tab[i] == '-' || tab[i] == '+')
		i++;
	while (tab[i] >= 48 && tab[i] <= 57)
		i++;
	return (i);
}
