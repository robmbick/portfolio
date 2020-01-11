/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:04:29 by bnetschu          #+#    #+#             */
/*   Updated: 2019/03/29 11:53:20 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	test(t_fdf_mlx *s, float *i)
{
	mlx_clear_window(s->mlx->mlx_ptr, s->mlx->win_ptr);
	isos(s->fdf, -0.523599 + i[0]);
	i[0] += 0.0175438596;
	if (i[0] > 1)
		i[0] = 0;
	centr(s->fdf);
	connect_line(s->fdf, s->mlx);
}

void	test1(t_fdf_mlx *s, float *i)
{
	mlx_clear_window(s->mlx->mlx_ptr, s->mlx->win_ptr);
	i[0] -= 0.0175438596;
	isos(s->fdf, -0.523599 + i[0]);
	if (i[0] < -0.4085969)
		i[0] = 0;
	centr(s->fdf);
	connect_line(s->fdf, s->mlx);
}

int		*mal_col(int *col)
{
	if (col == NULL)
	{
		col = malloc(sizeof(int));
		col[0] = 0;
	}
	return (col);
}

void	help_key_release(int key, t_fdf_mlx *param, int *col, float *i)
{
	if (key == 8)
		mlx_clear_window(param->mlx->mlx_ptr, param->mlx->win_ptr);
	else if (key == 13)
		test(param, i);
	else if (key == 1)
		test1(param, i);
	else if (key == 126)
		move_up_d(param, -10);
	else if (key == 125)
		move_up_d(param, 10);
	else if (key == 123)
		move_left_r(param, -10);
	else if (key == 124)
		move_left_r(param, 10);
	else if (key == 47)
		ch_col(param->fdf, param->mlx, col, 1);
	else if (key == 43)
		ch_col(param->fdf, param->mlx, col, -1);
	else if (key == 2)
		img_default(param->fdf, param->mlx);
	else if (key == 4)
		draw_help(param->mlx);
}

int		key_release(int key, t_fdf_mlx *param)
{
	static float	*i;
	static int		*col;

	col = mal_col(col);
	if (i == NULL)
	{
		i = malloc(sizeof(float));
		i[0] = 0.0175438596;
	}
	if (key == 53)
	{
		free(i);
		free(col);
		exit(0);
	}
	help_key_release(key, param, col, i);
	return (0);
}
