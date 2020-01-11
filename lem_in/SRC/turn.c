/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:38:22 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/13 14:14:22 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	way_weight(void)
{
	t_way	*way;
	int		i;

	g_way = g_way1;
	while (g_way != NULL)
	{
		i = 0;
		way = g_way;
		while (way != NULL)
		{
			i++;
			way = way->next;
		}
		g_way->weight = i;
		g_way = g_way->next_way;
	}
}

t_way	*tt(void)
{
	int		i;
	t_way	*s;

	g_way = g_way1;
	i = g_way->weight;
	s = g_way;
	while (g_way != NULL)
	{
		if (g_way->weight < i)
		{
			i = g_way->weight;
			s = g_way;
		}
		g_way = g_way->next_way;
	}
	s->weight++;
	return (s);
}

int		h_turn1(t_ants *ants, int kk)
{
	if (ants->way->edge->num != g_end)
	{
		if (ants->way->next->edge->here == 0)
		{
			if (ants->pr_way != NULL)
				ants->pr_way->edge->here = 0;
			ants->way->next->edge->here = 1;
			ants->pr_way = ants->way->next;
			ants->way = ants->way->next;
			if (kk == 0)
				ft_printf("L%i-%s", ants->num, ants->way->edge->name);
			else
				ft_printf(" L%i-%s", ants->num, ants->way->edge->name);
			if (ants->way->edge->num == g_end)
				ants->way->edge->here = 0;
			kk = 1;
		}
	}
	return (kk);
}

void	turn1(t_ants *ants)
{
	t_ants	*che;
	int		kk;

	while (ants != NULL)
	{
		ants->way = tt();
		che = ants;
		ants = ants->next;
	}
	ants = g_lst_ants;
	(g_w == 1) ? ft_printf(GREEN) : 0;
	while (che->way->edge->num != g_end)
	{
		ants = g_lst_ants;
		kk = 0;
		while (ants != NULL)
		{
			kk = h_turn1(ants, kk);
			ants = ants->next;
		}
		g_num_of_turn++;
		ft_printf("\n");
	}
	if (g_w == 1)
		ft_printf(RESET);
}

void	turn(void)
{
	t_ants	*ants;
	int		i;
	int		z;

	way_weight();
	z = 1;
	i = g_ants;
	ants = (t_ants*)malloc(sizeof(t_ants));
	ants->next = NULL;
	ants->pr_way = NULL;
	ants->num = z;
	g_lst_ants = ants;
	while (i-- != 1)
	{
		z++;
		ants->next = (t_ants*)malloc(sizeof(t_ants));
		ants->next->pr_way = NULL;
		ants->next->next = NULL;
		ants->next->num = z;
		ants = ants->next;
	}
	h_turn();
}
