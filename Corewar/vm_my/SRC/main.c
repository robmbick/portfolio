/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <vpalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:36:56 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/29 20:23:46 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	present_bots(void)
{
	t_deskriptor *tmp;

	tmp = g_deskript;
	ft_printf("Introducing contestants...\n");
	while (tmp)
	{
		ft_printf("* Player %d, weighing %d bytes, ", tmp->num, tmp->bot_size);
		ft_printf("\"%s\" (\"%s\") !\n", tmp->name_bot, tmp->comment);
		tmp = tmp->next;
	}
}

int		main(int argc, char **argv)
{
	t_tab	tab;

	tab.cycle_delta = 0;
	g_created_car = 0;
	g_nbr_cycles = -1;
	g_print = 0;
	g_carriages_alive = 0;
	if (argc > 1)
	{
		if (pars_bot(argc, argv))
		{
			present_bots();
			create_map();
			set_players_map();
			set_carriages();
			if (g_visual)
				cycle_vm(0, tab, 1);
			else
				cycle();
		}
	}
	else
		ft_printf(CYAN"Usage: ./corewar [-d N -v N] [-n N] [-p] \
<champion1.cor>! <...>\n"RESET);
	return (0);
}
