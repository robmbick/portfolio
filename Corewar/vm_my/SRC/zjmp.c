/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:15:22 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/29 15:15:37 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			zjmp(t_carriage *car)
{
	int		adr;
	int		tek_pos;

	tek_pos = car->i;
	adr = read_tdir(2, car->i);
	if (car->carry == 1)
	{
		car->i = next_position(car->i, adr % IDX_MOD);
	}
	else
		car->i = next_position(car->i, 3);
	if (g_print == 4 || g_print == 6)
	{
		if (car->carry == 1)
			ft_printf("P %4d | zjmp %d OK\n", car->num, adr);
		else
			ft_printf("P %4d | zjmp %d FAILED\n", car->num, adr);
	}
}

unsigned int	ldi1(char *next_arg, int n, t_carriage *car, t_data *d)
{
	unsigned int	nbr;

	g_marker = 1;
	if (next_arg[0 + n] == '0' && next_arg[1 + n] == '1' && check_reg(d->pos))
	{
		d->pos = next_position(d->pos, 1);
		return (car->r[next_position(g_map[d->pos], -1)]);
	}
	else if (next_arg[0 + n] == '1' && next_arg[1 + n] == '1')
	{
		nbr = d->tek_position + read_tdir(2, d->pos) % IDX_MOD;
		d->pos = next_position(d->pos, 2);
		return (nbr);
	}
	else if (next_arg[0 + n] == '1' && next_arg[1 + n] == '0')
	{
		nbr = read_tdir(2, d->pos);
		d->pos = next_position(d->pos, 2);
		return (nbr);
	}
	g_marker = 0;
	return (-1);
}

void			ldi(t_carriage *car)
{
	t_data	d;

	d.tek_position = car->i;
	car->i = next_position(car->i, 1);
	d.pos = car->i;
	d.next_arg = ft_itoa_basex(g_map[d.pos], 2, 'a');
	if ((d.nbr = ldi1(d.next_arg, 0, car, &d)) != -1 || g_marker)
		if (!(d.next_arg[2] == '1' && d.next_arg[3] == '1') &&
			((d.nbr2 = ldi1(d.next_arg, 2, car, &d)) != -1 || g_marker))
			if (d.next_arg[4] == '0' && d.next_arg[5] == '1' &&
														check_reg(d.pos))
			{
				d.adr = next_position(0, d.tek_position + (d.nbr + d.nbr2)
																	% IDX_MOD);
				car->r[g_map[d.pos + 1] - 1] = read_4bytes(d.adr);
				d.t = g_map[d.pos + 1] - 1;
				d.pos = next_position(d.pos, 1);
				if (g_print == 4 || g_print == 6)
					ft_printf("P %4d | ldi %d %d r%d\n       | -> load from \
%d + %d = %d (with pc and mod %d)\n", car->num, d.nbr, d.nbr2, d.t + 1, d.nbr,
												d.nbr2, d.nbr + d.nbr2, d.adr);
			}
	car->i = next_position(car->i, get_offset(3, d.next_arg, 2) + 1);
	free(d.next_arg);
}

void			sti(t_carriage *car)
{
	t_data	d;

	d.tek_position = car->i;
	car->i = next_position(car->i, 1);
	d.pos = car->i;
	d.next_arg = ft_itoa_basex(g_map[d.pos], 2, 'a');
	if (d.next_arg[0] == '0' && d.next_arg[1] == '1' && check_reg(d.pos))
	{
		d.pos = next_position(d.pos, 1);
		d.reg = g_map[d.pos] - 1;
		if ((d.nbr = ldi1(d.next_arg, 2, car, &d)) != -1 || g_marker)
			if (!(d.next_arg[4] == '1' && d.next_arg[5] == '1') &&
		((d.nbr2 = ldi1(d.next_arg, 4, car, &d)) != -1 || g_marker))
			{
				d.tek_position += (d.nbr + d.nbr2) % IDX_MOD;
				write_to_map(car->r[d.reg], d.tek_position);
				if (g_print == 4 || g_print == 6)
					ft_printf("P %4d | sti r%d %d %d\n       | -> store to %d \
+ %d = %d (with pc and mod %d)\n", car->num, d.reg + 1, d.nbr, d.nbr2, d.nbr,
									d.nbr2, d.nbr + d.nbr2, d.tek_position);
			}
	}
	car->i = next_position(car->i, get_offset(3, d.next_arg, 2) + 1);
	free(d.next_arg);
}
