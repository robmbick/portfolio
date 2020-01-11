/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:23:01 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/13 13:25:56 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	h_cr(t_lem *lem2, int i)
{
	t_link	*link;

	while (lem2->see != 0)
	{
		link = lem2->link;
		while (link != NULL)
		{
			if (link->room->see == i)
				break ;
			link = link->next;
		}
		i--;
		lem2 = link->room;
		g_way->next = (t_way*)malloc(sizeof(t_way));
		g_way->next->edge = lem2;
		g_way->next->next = NULL;
		g_way = g_way->next;
	}
}

void	create_way(t_lem *lem2)
{
	t_way	*s;

	g_way = (t_way*)malloc(sizeof(t_way));
	s = g_way1;
	if (s == NULL)
		g_way1 = g_way;
	else
	{
		while (s->next_way != NULL)
			s = s->next_way;
		s->next_way = g_way;
	}
	g_way->next_way = NULL;
	g_way->edge = lem2;
	h_cr(lem2, lem2->see - 1);
}
