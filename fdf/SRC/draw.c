/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:43:28 by bnetschu          #+#    #+#             */
/*   Updated: 2019/03/29 12:10:42 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				*ft_begin(int x, int y, int *resolution, int pix)
{
	int		*mas;

	mas = malloc(sizeof(int) * 2);
	mas[0] = resolution[0] / 2;
	mas[1] = resolution[1] / 2;
	while (y != 0)
	{
		mas[1] = mas[1] - pix;
		y--;
	}
	while (x != 0)
	{
		mas[0] = mas[0] - pix;
		x--;
	}
	return (mas);
}

void			start_d_in_fdf(t_fdf **fdf, int *begin, int pix)
{
	int i;
	int j;

	i = 0;
	j = 0;
	fdf[i][j].d_x = begin[0];
	fdf[i][j].d_y = begin[1];
	j++;
	while (i != fdf[0][0].y_max)
	{
		while (j != fdf[0][0].x_max)
		{
			fdf[i][j].d_x = begin[0] + pix;
			fdf[i][j].d_y = begin[1];
			begin[0] += pix;
			j++;
		}
		begin[0] = fdf[0][0].d_x - pix;
		begin[1] += pix;
		i++;
		j = 0;
	}
}

static void		connect_line_help(t_fdf **fdf, t_mlxptr *mlx,
					int *xy, int *xy_next_color)
{
	int i;
	int j;

	i = 0;
	while (i < fdf[0][0].x_max)
	{
		j = 0;
		while (j < fdf[0][0].y_max - 1)
		{
			xy[0] = fdf[j][i].x;
			xy[1] = fdf[j][i].y;
			xy_next_color[0] = fdf[j + 1][i].x;
			xy_next_color[1] = fdf[j + 1][i].y;
			xy_next_color[2] = fdf[j][i].color;
			xy_next_color[3] = fdf[j + 1][i].color;
			line(mlx, xy, xy_next_color, &xy_next_color[2]);
			j++;
		}
		i++;
	}
}

void			connect_line(t_fdf **fdf, t_mlxptr *mlx)
{
	int		xy[2];
	int		xy_next_color[4];
	int		i;
	int		j;

	j = 0;
	if (for_one_pix(fdf, mlx) == 0)
		return ;
	while (j < fdf[0][0].y_max)
	{
		i = 0;
		while (i < fdf[0][0].x_max - 1)
		{
			xy[0] = fdf[j][i].x;
			xy[1] = fdf[j][i].y;
			xy_next_color[0] = fdf[j][i + 1].x;
			xy_next_color[1] = fdf[j][i + 1].y;
			xy_next_color[2] = fdf[j][i].color;
			xy_next_color[3] = fdf[j][i + 1].color;
			line(mlx, xy, xy_next_color, &xy_next_color[2]);
			i++;
		}
		j++;
	}
	connect_line_help(fdf, mlx, xy, xy_next_color);
}

void			draw(t_fdf **fdf, int *resolutiot, t_mlxptr *mlx)
{
	int		*begin;
	int		pix;

	pix = resolutiot[2];
	begin = ft_begin(fdf[0][0].x_max / 2, fdf[0][0].y_max / 2, resolutiot, pix);
	start_d_in_fdf(fdf, begin, pix);
	iso(fdf, -0.523599);
	centr(fdf);
	connect_line(fdf, mlx);
	free(begin);
}
