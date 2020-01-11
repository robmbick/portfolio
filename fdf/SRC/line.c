/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:09:31 by bnetschu          #+#    #+#             */
/*   Updated: 2019/03/07 11:40:19 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	lengthx_big(int *xy1, t_mlxptr *mlx, int *length_and_dx, int *color)
{
	int		x;
	float	y;
	int		d;
	float	cl;

	cl = 0;
	if (color[0] != color[1])
		cl = color[1] - color[0];
	cl = cl / (length_and_dx[0]);
	x = xy1[0];
	y = xy1[1];
	d = -length_and_dx[1];
	length_and_dx[0]++;
	while (length_and_dx[0]--)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, roundf(y), color[0]);
		x += length_and_dx[3];
		d += 2 * length_and_dx[2];
		if (d > 0)
		{
			d -= 2 * length_and_dx[1];
			y += length_and_dx[4];
		}
		color[0] += cl;
	}
}

static void	lengthy_big(int *xy1, t_mlxptr *mlx, int *length_and_dx, int *color)
{
	float	x;
	int		y;
	int		d;
	float	cl;

	cl = 0;
	if (color[0] != color[1])
		cl = color[1] - color[0];
	cl = cl / (length_and_dx[0]);
	x = xy1[0];
	y = xy1[1];
	d = -length_and_dx[2];
	length_and_dx[0]++;
	while (length_and_dx[0]--)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, roundf(y), color[0]);
		d += 2 * length_and_dx[1];
		y += length_and_dx[4];
		if (d > 0)
		{
			d -= 2 * length_and_dx[2];
			x += length_and_dx[3];
		}
		color[0] += cl;
	}
}

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void		line(t_mlxptr *mlx, int *xy1, int *xy2, int *color)
{
	int		length_and_dx[7];

	length_and_dx[3] = (xy2[0] - xy1[0] >= 0 ? 1 : -1);
	length_and_dx[4] = (xy2[1] - xy1[1] >= 0 ? 1 : -1);
	length_and_dx[1] = ft_abs(xy2[0] - xy1[0]);
	length_and_dx[2] = ft_abs(xy2[1] - xy1[1]);
	length_and_dx[5] = xy1[0] * length_and_dx[1] + length_and_dx[2] * xy1[1];
	length_and_dx[6] = xy2[0] * length_and_dx[1] + length_and_dx[2] * xy2[1];
	if (length_and_dx[1] > length_and_dx[2])
		length_and_dx[0] = length_and_dx[1];
	else
		length_and_dx[0] = length_and_dx[2];
	if (length_and_dx[0] == 0)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, xy1[0], xy1[1], color[0]);
	else if (length_and_dx[2] <= length_and_dx[1])
		lengthx_big(xy1, mlx, length_and_dx, color);
	else
		lengthy_big(xy1, mlx, length_and_dx, color);
}
