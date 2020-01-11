/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <vpalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:10:26 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/29 20:08:58 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		cycle_die(int *max_check, int i)
{
	check_carriages_live();
	if (g_carriages == NULL)
		return (0);
	if (g_cycle_to_die <= 0)
		return (0);
	if (g_live_in_curent_cycle == 0 || g_live_in_curent_cycle >= NBR_LIVE - 1
		|| *max_check >= MAX_CHECKS - 1)
	{
		g_cycle_to_die -= CYCLE_DELTA;
		g_last_check = i;
		if (g_print == 2 || g_print == 6)
			ft_printf("Cycle to die is now %d\n", g_cycle_to_die);
		*max_check = 0;
	}
	else
		(*max_check)++;
	g_live_in_curent_cycle = 0;
	return (1);
}

void	carriage_one_cycle(void)
{
	t_carriage		*car;

	car = g_carriages;
	while (car != NULL)
	{
		car->i = next_position(car->i, 0);
		if (car->wait <= 0)
		{
			car->code_oper = g_map[car->i];
			if (car->code_oper > 0 && car->code_oper <= 16)
			{
				car->wait = g_op_wait[car->code_oper];
			}
			else
				car->i = next_position(car->i, 1);
		}
		car->wait--;
		if (car->wait == 0 && car->code_oper > 0 && car->code_oper <= 16)
			g_funcs[car->code_oper](car);
		car = car->next;
	}
}

void	print_winner(void)
{
	t_deskriptor	*tmp;

	tmp = g_deskript;
	while (tmp)
	{
		if (tmp->num == g_last_player_live)
		{
			ft_printf("Contestant %d, ", tmp->num);
			ft_printf("\"%s\", has won !\n", tmp->name_bot);
			return ;
		}
		tmp = tmp->next;
	}
}

void	print_map(void)
{
	int		z;

	z = 0;
	ft_printf("0x0000 : ");
	while (z < MEM_SIZE)
	{
		if (g_map[z] < 16)
			ft_printf("0");
		ft_printf("%x ", g_map[z]);
		if ((z + 1) % 32 == 0)
		{
			ft_printf("\n");
			if (z < MEM_SIZE - 1)
				ft_printf("%#.2x : ", z + 1);
		}
		z++;
	}
	exit(1);
}

void	cycle(void)
{
	size_t		i;
	int			max_check;

	i = 1;
	g_cycle_to_die = CYCLE_TO_DIE;
	g_live_in_curent_cycle = 0;
	max_check = 0;
	g_last_check = 0;
	while (1)
	{
		if (g_print == 2 || g_print == 6)
			ft_printf("It is now cycle %d\n", i);
		carriage_one_cycle();
		if ((g_cycle_to_die < 0 || ((i - g_last_check) % g_cycle_to_die == 0 &&
			cycle_die(&max_check, i) == 0)))
		{
			print_winner();
			break ;
		}
		if ((g_nbr_cycles != 0 && (size_t)g_nbr_cycles == i))
			print_map();
		i++;
	}
	exit(1);
}
