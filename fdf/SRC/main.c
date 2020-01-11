/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:03:17 by bnetschu          #+#    #+#             */
/*   Updated: 2019/03/29 12:18:35 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_help(t_mlxptr *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 0, 0, 45454
						, "for move you can use key : up, down, right, left");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 0, 15, 45454
						, "To clear press 'C'");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 0, 30, 45454
						, "You can use: '<','>','D','W','S' too");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 0, 45, 45454
						, "see this again - 'H");
}

int			closep(t_fdf_mlx *param)
{
	param = NULL;
	exit(0);
	return (0);
}

static int	usage(void)
{
	ft_putstr("Usage : ./fdf <filename>\n");
	exit(0);
	return (0);
}

void		dod(t_fdf **fdf)
{
	int			*resolut;
	t_mlxptr	*mlx;
	t_fdf_mlx	fdf_mlx;

	mlx = malloc(sizeof(mlx));
	mlx->mlx_ptr = mlx_init();
	resolut = resolution(fdf[0][0].x_max, fdf[0][0].y_max);
	fdf_mlx.resolution[0] = resolut[0];
	fdf_mlx.resolution[1] = resolut[1];
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, resolut[0], resolut[1], "fdf");
	draw_help(mlx);
	draw(fdf, resolut, mlx);
	fdf_mlx.fdf = fdf;
	fdf_mlx.mlx = mlx;
	free(resolut);
	mlx_hook(mlx->win_ptr, 17, 0, closep, &mlx);
	mlx_hook(mlx->win_ptr, 2, 0, key_release, &fdf_mlx);
	mlx_loop(mlx->mlx_ptr);
}

int			main(int argc, char **argv)
{
	t_fdf		**fdf;

	fdf = NULL;
	if (argc == 2)
	{
		if ((fdf = file_read(open(argv[1], O_RDONLY))) == NULL)
		{
			ft_putstr("error\n");
			exit(0);
			return (0);
		}
	}
	else
		return (usage());
	dod(fdf);
	return (0);
}
