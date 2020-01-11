/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_turn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:07:09 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/13 14:56:20 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_way(void)
{
	t_way	*way;
	t_way	*way1;

	way = g_way1;
	while (way != NULL)
	{
		way1 = way;
		ft_printf(MAGENTA"Way what we found\n"RESET);
		while (way1 != NULL)
		{
			ft_printf(BLUE": %s"RESET, way1->edge->name);
			way1 = way1->next;
		}
		ft_printf("\n");
		way = way->next_way;
	}
}

void	h_turn(void)
{
	print_map();
	g_num_of_turn = 0;
	turn1(g_lst_ants);
	if (g_w == 1)
	{
		print_way();
		ft_printf(YELLOW"Number of turn : %i\n"RESET, g_num_of_turn);
	}
}
