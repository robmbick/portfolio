/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 15:40:09 by bnetschu          #+#    #+#             */
/*   Updated: 2019/03/29 12:12:44 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		res_help(int *resolution)
{
	if (resolution[0] == 800)
	{
		resolution[0] = 1024;
		resolution[1] = 768;
	}
	else if (resolution[0] == 1024)
	{
		resolution[0] = 1400;
		resolution[1] = 1050;
	}
	else if (resolution[0] == 1400)
	{
		resolution[0] = 640;
		resolution[1] = 480;
		resolution[2] -= 5;
		if (resolution[2] == 5)
		{
			resolution[0] = 2048;
			resolution[1] = 1536;
			resolution[2] = 10;
			return (0);
		}
	}
	return (1);
}

int		*resolution(int x, int y)
{
	int		*resolution;
	int		sq;

	resolution = malloc(sizeof(int) * 3);
	resolution[2] = 30;
	resolution[0] = 640;
	resolution[1] = 480;
	sq = resolution[2] * sqrt(x * x + y * y);
	while (sq > resolution[0])
	{
		if (resolution[0] == 640)
		{
			resolution[0] = 800;
			resolution[1] = 600;
		}
		else if (res_help(resolution) == 0)
			return (resolution);
		sq = resolution[2] * sqrt(x * x + y * y);
	}
	return (resolution);
}

int		for_one_pix(t_fdf **fdf, t_mlxptr *mlx)
{
	if (fdf[0][0].y_max == 1 && fdf[0][0].x_max == 1)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,
				fdf[0][0].x, fdf[0][0].y, fdf[0][0].color);
		return (0);
	}
	return (1);
}
