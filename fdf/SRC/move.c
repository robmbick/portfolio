/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:04:23 by bnetschu          #+#    #+#             */
/*   Updated: 2019/03/29 11:53:12 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_up_d(t_fdf_mlx *param, int k)
{
	int i;
	int j;

	j = 0;
	if (param->resolution[1] < param->fdf[0][0].d_y + k)
		return ;
	else if (0 > param->fdf[param->fdf[0][0].y_max - 1]
										[param->fdf[0][0].x_max - 1].d_y + k)
		return ;
	while (j != param->fdf[0][0].y_max)
	{
		i = 0;
		while (i != param->fdf[0][0].x_max)
		{
			param->fdf[j][i].y = param->fdf[j][i].y + k;
			param->fdf[j][i].d_y = param->fdf[j][i].d_y + k;
			i++;
		}
		j++;
	}
	mlx_clear_window(param->mlx->mlx_ptr, param->mlx->win_ptr);
	connect_line(param->fdf, param->mlx);
}

void	move_left_r(t_fdf_mlx *param, int k)
{
	int i;
	int j;

	j = 0;
	if (param->resolution[0] < param->fdf[0][0].d_x + k)
		return ;
	else if (0 > param->fdf[param->fdf[0][0].y_max - 1]
										[param->fdf[0][0].x_max - 1].d_x + k)
		return ;
	while (j != param->fdf[0][0].y_max)
	{
		i = 0;
		while (i != param->fdf[0][0].x_max)
		{
			param->fdf[j][i].x = param->fdf[j][i].x + k;
			param->fdf[j][i].d_x = param->fdf[j][i].d_x + k;
			i++;
		}
		j++;
	}
	mlx_clear_window(param->mlx->mlx_ptr, param->mlx->win_ptr);
	connect_line(param->fdf, param->mlx);
}
