/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 09:41:44 by bnetschu          #+#    #+#             */
/*   Updated: 2019/01/30 17:34:42 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef	struct		s_lst
{
	int				num;
	char			*matrix[4];
	char			**tetra;
	int				h;
	int				l;
	struct s_lst	*next;
}					t_lst;

int					check_grill(char **matrix);
t_lst				*ft_read(int fd);
void				lst_free(t_lst *list);
void				rewrite_tetra(t_lst *list);
int					check_grill_square(char **matrix, int n);
void				square(t_lst *list, int num);
void				clear_square(char **square, char t, int n);
int					put_the_tetra(char **square, t_lst *list, int n);
int					check_tetra_position(char **square, t_lst *list, int n);
void				ft_point_square(char **square, int n);
void				ft_print_square(char **square, int n);
int					check_in_tetra(t_lst *list, char **square);
int					best_way(char **square, int *ideal);
int					write_in_sq(char **square,
						char **tetra, int *ideal, char t);
void				clear_sq(char **square, char t);
int					help_put_the_tetra(char **square,
						t_lst *list, int ch, int n);
int					help_check(char t, char **square);
char				**ft_square_malloc(char **square, int n);
void				ft_free_square(char **s, int n);
#endif
