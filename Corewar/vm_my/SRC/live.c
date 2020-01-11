/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 12:57:59 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/29 16:47:11 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	live(t_carriage *car)
{
	int		tdir;
	int		prev;

	tdir = read_tdir(4, car->i);
	car->live++;
	prev = tdir;
	(tdir < 0) ? tdir *= -1 : 0;
	if (tdir > 0 && tdir <= g_players_in_game && prev < 0)
	{
		if (g_print == 4 || g_print == 6)
			ft_printf("P %4d | live %d\n", car->num, -tdir);
		g_last_player_live = tdir;
		g_live_in_curent_cycle++;
	}
	else if (g_print == 4 || g_print == 6)
		ft_printf("P %4d | live %d\n", car->num, prev);
	car->i = next_position(car->i, 5);
}

int		get_offset(int argc, char *next_arg, int size_dir)
{
	int		rez;
	int		i;

	rez = 0;
	i = 0;
	while (i < argc * 2)
	{
		if (next_arg[i] == '1' && next_arg[i + 1] == '0')
			rez += size_dir;
		else if (next_arg[i] == '1' && next_arg[i + 1] == '1')
			rez += 2;
		else if (next_arg[i] == '0' && next_arg[i + 1] == '1')
			rez += 1;
		i += 2;
	}
	return (rez);
}

void	ld(t_carriage *car)
{
	char	*next_arg;
	t_data	d;

	car->i = next_position(car->i, 1);
	d.pos = car->i;
	next_arg = ft_itoa_basex(g_map[d.pos], 2, 'a');
	d.reg = 0;
	d.off = (next_arg[0] == '1' && next_arg[1] == '0') ? 4 : 2;
	if (next_arg[2] == '0' && next_arg[3] == '1' && check_reg(d.pos + d.off))
	{
		if (next_arg[0] == '1' && next_arg[1] == '0')
		{
			car->r[g_map[d.pos + 5] - 1] = read_tdir(4, d.pos);
			d.reg = g_map[d.pos + 5] - 1;
			car->carry = (car->r[g_map[d.pos + 5] - 1] == 0) ? 1 : 0;
			if (g_print == 4 || g_print == 6)
				ft_printf("P %4d | ld %d r%d\n", car->num,
											car->r[d.reg], d.reg + 1);
		}
		else if (next_arg[0] == '1' && next_arg[1] == '1')
			ld_h(&d, car);
	}
	car->i = next_position(car->i, 1 + get_offset(2, next_arg, 4));
	free(next_arg);
}

void	st(t_carriage *car)
{
	char	*next_arg;
	t_data	d;

	car->i = next_position(car->i, 1);
	d.pos = car->i;
	next_arg = ft_itoa_basex(g_map[d.pos], 2, 'a');
	if (next_arg[0] == '0' && next_arg[1] == '1' && check_reg(d.pos))
	{
		if (next_arg[2] == '0' && next_arg[3] == '1' && check_reg(d.pos + 1))
		{
			car->r[g_map[d.pos + 2] - 1] = car->r[g_map[d.pos + 1] - 1];
			if (g_print == 4 || g_print == 6)
				ft_printf("P %4d | st r%d %d\n", car->num,
								g_map[d.pos + 1], g_map[d.pos + 2]);
		}
		else if (next_arg[2] == '1' && next_arg[3] == '1')
			st_h(&d, car);
	}
	car->i = next_position(car->i, get_offset(2, next_arg, 4) + 1);
	free(next_arg);
}

void	add(t_carriage *car)
{
	t_data	d;

	car->i = next_position(car->i, 1);
	d.pos = car->i;
	d.next_arg = ft_itoa_basex(g_map[d.pos], 2, 'a');
	if (d.next_arg[0] == '0' && d.next_arg[1] == '1' && check_reg(d.pos))
	{
		d.pos = next_position(d.pos, 1);
		d.t_reg = g_map[d.pos] - 1;
		if (d.next_arg[2] == '0' && d.next_arg[3] == '1' && check_reg(d.pos))
		{
			d.pos = next_position(d.pos, 1);
			d.t_reg1 = g_map[d.pos] - 1;
			if (d.next_arg[4] == '0' && d.next_arg[5] == '1' &&
															check_reg(d.pos))
			{
				add_h(&d, car);
			}
		}
	}
	car->i = next_position(car->i, get_offset(3, d.next_arg, 4) + 1);
	free(d.next_arg);
}
