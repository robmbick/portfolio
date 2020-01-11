/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:22:18 by bnetschu          #+#    #+#             */
/*   Updated: 2019/03/29 12:12:04 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# define NONS(x) (x > 0 ? pow(16, x) : 1)

typedef struct			s_fdf
{
	int					i;
	float				d_z;
	float				d_x;
	float				d_y;
	float				x;
	float				y;
	float				z;
	int					color;
	int					x_max;
	int					y_max;
}						t_fdf;

typedef struct			s_fdf_mlx
{
	struct s_fdf		**fdf;
	struct s_mlxptr		*mlx;
	int					resolution[3];
}						t_fdf_mlx;

typedef struct			s_mlxptr
{
	void				*mlx_ptr;
	void				*win_ptr;
}						t_mlxptr;

typedef struct			s_tab
{
	int					x_max;
	int					y_max;
}						t_tab;

void					line(t_mlxptr *mlx, int *xy1, int *xy2, int *color);
t_fdf					**file_read(int fd);
void					draw(t_fdf **fdf, int *resolutiot, t_mlxptr *mlx);
int						*resolution(int x, int y);
void					iso(t_fdf **fdf, float angl);
void					centr(t_fdf **fdf);
void					connect_line(t_fdf **fdf, t_mlxptr *mlx);
int						color_found(char *str);
int						ft_lentab(char *s, char c);
int						check_tab(char *tab);
t_fdf					**ft_cast(char **tab, t_fdf **fdf, int y, int x);
void					iso(t_fdf **fdf, float angl);
void					centr(t_fdf **fdf);
void					move_up_d(t_fdf_mlx *param, int k);
void					move_left_r(t_fdf_mlx *param, int k);
void					ch_col(t_fdf **fdf, t_mlxptr *mlx, int *col, int it);
void					isos(t_fdf **fdf, float angl);
int						key_release(int key, t_fdf_mlx	*param);
void					img_default(t_fdf **fdf, t_mlxptr *mlx);
void					draw_help(t_mlxptr *mlx);
void					delete_t_in_line(char *str);
int						check_tab_k(char *tab, int i, int *k);
int						help_ch_tab(int i, char *tab);
int						for_one_pix(t_fdf **fdf, t_mlxptr *mlx);
#endif
