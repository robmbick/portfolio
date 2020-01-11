/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:37:17 by bnetschu          #+#    #+#             */
/*   Updated: 2019/06/06 16:40:56 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

int			g_res;
int			g_x;
int			g_y;
int			g_point[3];

typedef struct	s_filler
{
	char	player;
	int		high;
	int		width;
	int		cr_map;
	char	**map;
	int		high_piece;
	int		width_piece;
	char	**map_piece;
}				t_filler;

void			map_size(t_filler *fill, char *line);
void			player(char *line, t_filler *fill);
void			map_re(t_filler *fill, char *line);
void			r_point(int *point, t_filler *fill);
int				h_check_piece(t_filler *fill, int *m_p, int i, int j);

#endif
