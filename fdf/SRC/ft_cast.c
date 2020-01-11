/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 10:16:48 by bnetschu          #+#    #+#             */
/*   Updated: 2019/03/28 11:05:22 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			img_default(t_fdf **fdf, t_mlxptr *mlx)
{
	int i;
	int j;

	j = 0;
	while (j != fdf[0][0].y_max)
	{
		i = 0;
		while (i != fdf[0][0].x_max)
		{
			fdf[j][i].x = fdf[j][i].d_x;
			fdf[j][i].y = fdf[j][i].d_y;
			i++;
		}
		j++;
	}
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	connect_line(fdf, mlx);
}

static void		free_ft_cast(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void		after_ft_free(int y, t_fdf **fdf)
{
	int i;

	i = 0;
	while (i < y)
	{
		free(fdf[i]);
		i++;
	}
	free(fdf);
}

static int		help_ft_cast(int *for_tab, int y, char **tab, t_fdf **fdf)
{
	int check;

	check = 0;
	y = 0;
	if ((check = check_tab(tab[for_tab[2]])) == 1)
		fdf[for_tab[0]][for_tab[1]].color = color_found(tab[for_tab[2]] + 4);
	else if (check == 0)
		fdf[for_tab[0]][for_tab[1]].color = 16777215;
	else
	{
		free_ft_cast(tab);
		after_ft_free(for_tab[0] + 1, fdf);
		return (0);
	}
	return (1);
}

t_fdf			**ft_cast(char **tab, t_fdf **fdf, int y, int x)
{
	int		for_tab[3];

	for_tab[2] = 0;
	for_tab[0] = 0;
	while (for_tab[0] < y)
	{
		for_tab[1] = 0;
		fdf[for_tab[0]] = (t_fdf*)malloc(sizeof(t_fdf) * x);
		while (for_tab[1] < x)
		{
			if ((help_ft_cast(for_tab, y, tab, fdf)) == 0)
				return (NULL);
			fdf[for_tab[0]][for_tab[1]].d_z = ft_atoi(tab[for_tab[2]]);
			for_tab[1]++;
			for_tab[2]++;
		}
		for_tab[0]++;
	}
	fdf[0][0].x_max = x;
	fdf[0][0].y_max = y;
	free_ft_cast(tab);
	return (fdf);
}
