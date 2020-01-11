/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 16:31:54 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/29 16:45:42 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	sub_n(t_data *d, t_carriage *car)
{
	d->t_reg2 = g_map[d->pos + 1] - 1;
	car->r[d->t_reg2] = car->r[d->t_reg] - car->r[g_map[d->pos] - 1];
	car->carry = (car->r[d->t_reg2] == 0) ? 1 : 0;
	d->pos = next_position(d->pos, 1);
	if (g_print == 4 || g_print == 6)
		ft_printf("P %4d | sub r%d r%d r%d\n", car->num,
				d->t_reg + 1, d->t_reg1 + 1, d->t_reg2 + 1);
}

void	ld_h(t_data *d, t_carriage *car)
{
	d->tind = d->pos - 1 + read_tdir(2, d->pos) % IDX_MOD;
	d->reg = g_map[d->pos + 3] - 1;
	car->r[g_map[d->pos + 3] - 1] = read_4bytes(d->tind);
	car->carry = (car->r[g_map[d->pos + 3] - 1] == 0) ? 1 : 0;
	if (g_print == 4 || g_print == 6)
		ft_printf("P %4d | ld %d r%d\n", car->num,
									car->r[d->reg], d->reg + 1);
}

void	st_h(t_data *d, t_carriage *car)
{
	d->pos = next_position(d->pos, 1);
	d->t = read_tdir(2, d->pos);
	d->tind = d->pos - 2 + read_tdir(2, d->pos) % IDX_MOD;
	d->reg = g_map[d->pos] - 1;
	write_to_map(car->r[d->reg], d->tind);
	if (g_print == 4 || g_print == 6)
		ft_printf("P %4d | st r%d %d\n",
					car->num, d->reg + 1, d->t);
}

int		check_reg(int a)
{
	a = next_position(a, 1);
	a = g_map[a];
	if (a >= 1 && a <= 16)
		return (1);
	return (0);
}

void	add_h(t_data *d, t_carriage *car)
{
	d->t_reg2 = g_map[d->pos + 1] - 1;
	car->r[d->t_reg2] = car->r[d->t_reg] + car->r[g_map[d->pos] - 1];
	car->carry = (car->r[d->t_reg2] == 0) ? 1 : 0;
	d->pos = next_position(d->pos, 1);
	if (g_print == 4 || g_print == 6)
		ft_printf("P %4d | add r%d r%d r%d\n",
		car->num, d->t_reg + 1, d->t_reg1 + 1, d->t_reg2 + 1);
}
