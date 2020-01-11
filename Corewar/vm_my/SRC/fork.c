/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:01:54 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/29 16:55:50 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	copy_carriage(t_carriage *car, int adr)
{
	int	i;

	i = 0;
	while (i < REG_NUMBER)
	{
		g_carriages->r[i] = car->r[i];
		i++;
	}
	g_carriages->live = car->live;
	g_carriages->carry = car->carry;
	g_carriages->i = adr;
}

void	op_fork(t_carriage *car)
{
	int		tdir;
	int		adr;

	tdir = read_tdir(2, car->i);
	create_carriage(car->num, 0, car->own);
	adr = car->i + (tdir % IDX_MOD);
	copy_carriage(car, adr);
	car->i = next_position(car->i, 3);
	if (g_print == 4 || g_print == 6)
		ft_printf("P %4d | fork %d (%d)\n", car->num, tdir, adr);
}

void	lld2(t_carriage *car, int pos, char *next_arg)
{
	int	reg;

	if (next_arg[0] == '1' && next_arg[1] == '0' &&
					check_reg(next_position(pos, 5)))
	{
		reg = g_map[next_position(pos, 5)] - 1;
		car->r[reg] = read_tdir(4, pos);
		car->carry = (car->r[reg] == 0) ? 1 : 0;
		if (g_print == 4 || g_print == 6)
		{
			ft_printf("P %4d | lld %d r%d\n", car->num, car->r[reg], reg + 1);
		}
	}
	else if (next_arg[0] == '1' && next_arg[1] == '1')
	{
		reg = g_map[next_position(pos, 3)] - 1;
		car->r[reg] = read_4bytes(pos - 1 + read_tdir(2, pos));
		car->carry = (car->r[reg] == 0) ? 1 : 0;
		if (g_print == 4 || g_print == 6)
			ft_printf("P %4d | lld %d r%d\n", car->num, car->r[reg], reg + 1);
	}
}

void	lld(t_carriage *car)
{
	char	*next_arg;
	int		pos;

	car->i = next_position(car->i, 1);
	pos = car->i;
	next_arg = ft_itoa_basex(g_map[pos], 2, 'a');
	if (next_arg[2] == '0' && next_arg[3] == '1' && check_reg(pos +
		((next_arg[0] == '1' && next_arg[1] == '0') ? 4 : 2)))
	{
		lld2(car, pos, next_arg);
	}
	car->i = next_position(car->i, 1 + get_offset(2, next_arg, 4));
	free(next_arg);
}

void	lldi(t_carriage *car)
{
	t_data	d;

	d.tek_position = car->i;
	car->i = next_position(car->i, 1);
	d.pos = car->i;
	d.next_arg = ft_itoa_basex(g_map[d.pos], 2, 'a');
	if ((d.nbr = ldi1(d.next_arg, 0, car, &d)) != -1 || g_marker)
		if (!(d.next_arg[2] == '1' && d.next_arg[3] == '1') &&
((d.nbr2 = ldi1(d.next_arg, 2, car, &d)) != -1 || g_marker))
		{
			if (d.next_arg[4] == '0' && d.next_arg[5] == '1' &&
												check_reg(d.pos))
			{
				d.adr = next_position(0, d.tek_position + (d.nbr + d.nbr2));
				car->r[g_map[d.pos + 1] - 1] = read_4bytes(d.adr);
				d.t = g_map[d.pos + 1] - 1;
				d.pos = next_position(d.pos, 1);
				if (g_print == 4 || g_print == 6)
					ft_printf("P %4d | lldi %d %d r%d\n       \
| -> load from %d + %d = %d (with pc and mod %d)\n", car->num,
				d.nbr, d.nbr2, d.t + 1, d.nbr, d.nbr2, d.nbr + d.nbr2, d.adr);
			}
		}
	car->i = next_position(car->i, get_offset(3, d.next_arg, 2) + 1);
	free(d.next_arg);
}
