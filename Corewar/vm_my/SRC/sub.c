/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:41:44 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/29 16:32:17 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			sub(t_carriage *car)
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
				sub_n(&d, car);
			}
		}
	}
	car->i = next_position(car->i, get_offset(3, d.next_arg, 4) + 1);
	free(d.next_arg);
}

unsigned int	and1(char *next_arg, int n, t_carriage *car, t_data *d)
{
	unsigned int	nbr;

	g_marker = 1;
	if (next_arg[0 + n] == '0' && next_arg[1 + n] == '1' && check_reg(d->pos))
	{
		d->pos = next_position(d->pos, 1);
		return (car->r[g_map[d->pos] - 1]);
	}
	else if (next_arg[0 + n] == '1' && next_arg[1 + n] == '1')
	{
		nbr = d->tek_position + read_tdir(2, d->pos) % IDX_MOD;
		d->pos = next_position(d->pos, 2);
		return (nbr);
	}
	else if (next_arg[0 + n] == '1' && next_arg[1 + n] == '0')
	{
		nbr = read_tdir(4, d->pos);
		d->pos = next_position(d->pos, 4);
		return (nbr);
	}
	g_marker = 0;
	return (-1);
}

void			op_and(t_carriage *car)
{
	t_data	d;

	d.tek_position = car->i;
	car->i = next_position(car->i, 1);
	d.pos = car->i;
	d.next_arg = ft_itoa_basex(g_map[d.pos], 2, 'a');
	if ((d.nbr = and1(d.next_arg, 0, car, &d)) != -1 || g_marker)
		if ((d.nbr2 = and1(d.next_arg, 2, car, &d)) != -1 || g_marker)
			if (d.next_arg[4] == '0' && d.next_arg[5] == '1' &&
													check_reg(d.pos))
			{
				d.pos = next_position(d.pos, 1);
				d.reg = g_map[d.pos] - 1;
				car->r[d.reg] = d.nbr & d.nbr2;
				car->carry = (car->r[d.reg] == 0) ? 1 : 0;
				if (g_print == 4 || g_print == 6)
					ft_printf("P %4d | and %d %d r%d\n", car->num, d.nbr,
													d.nbr2, d.reg + 1);
			}
	car->i = next_position(car->i, get_offset(3, d.next_arg, 4) + 1);
	free(d.next_arg);
}

void			op_or(t_carriage *car)
{
	t_data	d;

	d.tek_position = car->i;
	d.reg = 15;
	car->i = next_position(car->i, 1);
	d.pos = car->i;
	d.next_arg = ft_itoa_basex(g_map[d.pos], 2, 'a');
	if ((d.nbr = and1(d.next_arg, 0, car, &d)) != -1 || g_marker)
		if ((d.nbr2 = and1(d.next_arg, 2, car, &d)) != -1 || g_marker)
			if (ft_strlen(d.next_arg) == 8 && d.next_arg[4] == '0' &&
							d.next_arg[5] == '1' && check_reg(d.pos))
			{
				d.reg = g_map[d.pos + 1] - 1;
				car->r[d.reg] = d.nbr | d.nbr2;
				car->carry = (car->r[d.reg] == 0) ? 1 : 0;
				if (g_print == 4 || g_print == 6)
					ft_printf("P %4d | or %d %d r%d\n", car->num,
										d.nbr, d.nbr2, d.reg + 1);
			}
	car->i = next_position(car->i, get_offset(3, d.next_arg, 4) + 1);
	free(d.next_arg);
}

void			op_xor(t_carriage *car)
{
	t_data	d;

	d.tek_position = car->i;
	d.reg = 15;
	car->i = next_position(car->i, 1);
	d.pos = car->i;
	d.next_arg = ft_itoa_basex(g_map[d.pos], 2, 'a');
	if ((d.nbr = and1(d.next_arg, 0, car, &d)) != -1 || g_marker)
		if ((d.nbr2 = and1(d.next_arg, 2, car, &d)) != -1 || g_marker)
			if (ft_strlen(d.next_arg) == 8 && d.next_arg[4] == '0' &&
							d.next_arg[5] == '1' && check_reg(d.pos))
			{
				d.reg = g_map[d.pos + 1] - 1;
				car->r[d.reg] = d.nbr ^ d.nbr2;
				car->carry = (car->r[d.reg] == 0) ? 1 : 0;
				if (g_print == 4 || g_print == 6)
					ft_printf("P %4d | xor %d %d r%d\n", car->num,
										d.nbr, d.nbr2, d.reg + 1);
			}
	car->i = next_position(car->i, get_offset(3, d.next_arg, 4) + 1);
	free(d.next_arg);
}
