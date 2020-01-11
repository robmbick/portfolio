/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <vpalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:36:35 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/29 20:13:28 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "../libft/libft.h"
# include <time.h>
# include <ncurses.h>

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

typedef	struct	s_deskriptor
{
	char				*name;
	int					num;
	int					bot_size;
	int					fd;
	int					start_pos;
	int					live;
	char				*name_bot;
	char				*comment;
	uint8_t				*code;
	struct s_deskriptor	*next;
}				t_deskriptor;

typedef	struct	s_data
{
	int		nbr;
	int		nbr2;
	int		tek_position;
	int		tek_pos;
	int		adr;
	int		t;
	int		reg;
	int		tind;
	int		pos;
	int		off;
	int		t_reg;
	int		t_reg1;
	int		t_reg2;
	char	*next_arg;
}				t_data;

typedef struct	s_carriage
{
	int					num;
	int					carry;
	int					i;
	int					code_oper;
	int					wait;
	int					live;
	int					own;
	unsigned int		r[REG_NUMBER];
	struct s_carriage	*next;
}				t_carriage;

typedef struct	s_tab
{
	bool				is_running;
	int					cycles_per_sec;
	unsigned int		cycles;
	unsigned int		processes;
	int					live_breakdown_for_cur;
	int					live_breakdown_for_last;
	unsigned int		cycle_to_die;
	unsigned int		cycle_delta;
	unsigned int		nbr_live;
	unsigned int		max_checks;
	int					y;
	clock_t				offset;
}				t_tab;

WINDOW			*g_win_map;
WINDOW			*g_win_tab;
t_tab			*tab_init(t_tab *tab);
void			carriage_one_cycle(void);
int				cycle_die(int *max_check, int i);
clock_t			get_last_time(t_tab *tab);
void			map_win_refresh(int i);
void			map_win_car(int i, int y, int x, t_carriage *car);
/*
** dod pars
*/
int				check_line_for_n(char **argv, t_deskriptor *des, int ss);
void			check_line_for_n_norm(char **argv, t_deskriptor *des);
void			check_str_for_cor(char *lin);
int				check_deskript_num(int num);
int				check_line_for_dump(char **argv, int ss);
/*
** op help
*/
void			add_h(t_data *d, t_carriage *car);
void			st_h(t_data *d, t_carriage *car);
void			ld_h(t_data *d, t_carriage *car);
void			sub_n(t_data *d, t_carriage *car);
/*
** dod op
*/
int				next_position(int value, int offset);
void			copy_carriage(t_carriage *car, int adr);
int				read_tdir(int size, int	adr);
unsigned int	ldi1(char *next_arg, int n, t_carriage *car, t_data *d);
void			write_to_map(unsigned int data, int pos);
int				read_4bytes(int	adr);
int				check_reg(int a);
void			print_map();
int				get_offset(int argc, char *next_arg, int size_dir);
/*
** op_func
*/
void			live(t_carriage *car);
void			ld(t_carriage *car);
void			st(t_carriage *car);
void			add(t_carriage *car);
void			sub(t_carriage *car);
void			op_and(t_carriage *car);
void			op_or(t_carriage *car);
void			op_xor(t_carriage *car);
void			zjmp(t_carriage *car);
void			ldi(t_carriage *car);
void			sti(t_carriage *car);
void			op_fork(t_carriage *car);
void			lld(t_carriage *car);
void			lldi(t_carriage *car);
void			lfork(t_carriage *car);
void			aff(t_carriage *car);
/*
** op_func
*/
typedef	void	(*t_funcs)(t_carriage*);
static t_funcs	g_funcs[17] = {
	NULL,
	live,
	ld,
	st,
	add,
	sub,
	op_and,
	op_or,
	op_xor,
	zjmp,
	ldi,
	sti,
	op_fork,
	lld,
	lldi,
	lfork,
	aff
};
static int		g_op_wait[17] = {
	0,
	10,
	5,
	5,
	10,
	10,
	6,
	6,
	6,
	20,
	25,
	25,
	800,
	10,
	50,
	1000,
	2
};
int				g_visual;
ssize_t			g_cycle_to_die;
int				g_last_player_live;
int				g_live_in_curent_cycle;
t_carriage		*g_carriages;
t_deskriptor	*g_kostul;
t_deskriptor	*g_deskript;
int				g_nbr_cycles;
uint8_t			*g_map;
int				g_players_in_game;
int				g_last_check;
int				g_created_car;
int				g_marker;
int				g_print;
int				g_cycle;
int				g_carriages_alive;

void			cycle();
void			check_file();
int				pars_bot(int argc, char **argv);
void			read_code(t_deskriptor *des);
int				read_magic_header(int fd);
void			read_name(t_deskriptor *des);
void			read_comment(t_deskriptor *des);
void			create_map();
void			set_players_map();
void			set_carriages();
int				get_players_count();
void			check_carriages_live();
void			create_carriage(int num, int pos, int own);
char			*ft_itoa_basex(unsigned long long int nbr, int base, int x);

void			cycle_vm();
bool			key_hook(t_tab *tab, int key);
void			first_print_tab(t_tab *tab);
void			tab_info_print(t_tab *tab);
t_tab			*tab_init(t_tab *tab);
void			formating_print(char *s, const chtype ch, int x, int y);

#endif
