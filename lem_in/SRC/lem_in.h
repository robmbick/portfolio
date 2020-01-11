/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:12:59 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/13 14:08:51 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

int					g_fd;

typedef struct	s_ants
{
	int				num;
	struct s_way	*way;
	struct s_ants	*next;
	struct s_way	*pr_way;
}				t_ants;

typedef	struct	s_way
{
	int				weight;
	struct s_lem	*edge;
	struct s_way	*next_way;
	struct s_way	*next;
}				t_way;

typedef	struct	s_link
{
	struct s_lem	*room;
	struct s_link	*next;
}				t_link;

typedef struct	s_read
{
	char			*str;
	struct s_read	*next;
}				t_read;

typedef struct	s_lem
{
	int				num;
	int				st_end;
	char			*name;
	int				x;
	int				y;
	int				see;
	int				here;
	struct s_lem	*next;
	struct s_link	*link;
}				t_lem;

int					g_pr;
int					g_w;
int					g_num_of_turn;
t_ants				*g_lst_ants;
t_way				*g_way1;
t_way				*g_way;
t_lem				*g_lem;
int					g_ants;
int					g_ch_s_en[2];
int					g_end;
t_read				*g_buf;
t_read				*g_buf1;

void			h_turn(void);
void			turn1(t_ants *ants);
int				h_rc_pars(void);
void			h_ret_link(t_lem *lem1, t_lem *lem2);
int				norm_pars(char *line);
void			ini_ft_pars(void);
int				remb(char *line);
int				check_command(char *line);
void			print_map();
void			read_map(char *line);
void			turn();
void			create_way(t_lem *lem2);
void			found_way(t_lem *lem, int *ch, t_lem *lem1, t_lem *lem2);
void			ft_start();
int				h_pars_co(t_lem *lem2, t_lem *lem, char *line);
t_lem			*ft_pars(void);
t_lem			*add_list_lem(char *name, int num, int *xy, int st_end);
int				pars_line(char *line, int i);
t_lem			*pars_connect(t_lem *lem, char *line);
t_lem			*pars_room(char *line, int num, int st_end, t_lem *lem);
t_lem			*ft_h_pars(char *line, t_lem *lem, int i, int k);
t_lem			*ft_hh_pars(char *line, t_lem *lem, int *i);
t_lem			*ft_hhh_pars(char *line, t_lem *lem, int *i);
#endif
