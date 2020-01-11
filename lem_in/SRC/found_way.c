/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:53:42 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/13 11:35:45 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	numer_mod(t_link *link, int i, int *ch)
{
	while (link != NULL)
	{
		if (link->room->see == 0 && link->room->num != ch[1])
			link->room->see = i;
		link = link->next;
	}
}

int			bfs_mod(t_lem *lem1, int *ch)
{
	int		i;
	int		check;

	check = 1;
	i = 1;
	numer_mod(lem1->link, 1, ch);
	while (check == 1)
	{
		check = 0;
		lem1 = g_lem;
		while (lem1 != NULL)
		{
			if (lem1->see == i)
			{
				numer_mod(lem1->link, i + 1, ch);
				check = 1;
			}
			if (lem1->see != 0 && lem1->num == ch[0])
				return (1);
			lem1 = lem1->next;
		}
		i++;
	}
	return (0);
}

int			check(t_way *way, int i)
{
	g_way = g_way1;
	while (g_way != NULL)
	{
		way = g_way;
		while (way != NULL)
		{
			if (way->edge->num == i)
				return (1);
			way = way->next;
		}
		g_way = g_way->next_way;
	}
	return (0);
}

void		found_way(t_lem *lem, int *ch, t_lem *lem1, t_lem *lem2)
{
	while (lem != NULL)
	{
		lem->see = 0;
		if (check(g_way1, lem->num) == 1 &&
			lem->num != ch[0] && lem->num != ch[1])
			lem->see = 10000;
		lem = lem->next;
	}
	while (bfs_mod(lem1, ch) == 1)
	{
		create_way(lem2);
		lem = g_lem;
		while (lem != NULL)
		{
			lem->see = 0;
			if (check(g_way1, lem->num) == 1 &&
				lem->num != ch[0] && lem->num != ch[1])
				lem->see = 10000;
			lem = lem->next;
		}
	}
	turn(g_way1, g_lem);
}
