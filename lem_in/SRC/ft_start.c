/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:01:39 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/13 13:23:28 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	numer(t_link *link, int i, int *ch)
{
	while (link != NULL)
	{
		if (link->room->see == 0 && link->room->num != ch[1])
			link->room->see = i;
		link = link->next;
	}
}

int		bfs(t_lem *lem1, int *ch)
{
	int		i;
	int		check;

	check = 1;
	i = 1;
	numer(lem1->link, 1, ch);
	while (check == 1)
	{
		check = 0;
		lem1 = g_lem;
		while (lem1 != NULL)
		{
			if (lem1->see == i)
			{
				numer(lem1->link, i + 1, ch);
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

void	norm_ft_start(t_lem **lem, int *ch)
{
	g_end = ch[1];
	if (bfs(lem[1], ch) == 1)
	{
		create_way(lem[2]);
		if (g_way1->edge->num == ch[0] && g_way1->next->edge->num == ch[1])
			turn();
		else
			found_way(g_lem, ch, lem[1], lem[2]);
	}
	else
		ft_printf(RED"ERROR! NO WAY !\n"RESET);
}

void	ft_start(void)
{
	t_lem	*lem[3];
	int		ch[2];

	lem[0] = g_lem;
	ch[0] = -1;
	ch[1] = -1;
	while (lem[0] != NULL)
	{
		if (lem[0]->st_end == 1)
		{
			lem[2] = lem[0];
			ch[0] = lem[0]->num;
		}
		else if (lem[0]->st_end == -1)
		{
			lem[1] = lem[0];
			ch[1] = lem[0]->num;
		}
		if (ch[0] >= 0 && ch[1] >= 0)
			break ;
		lem[0] = lem[0]->next;
	}
	norm_ft_start(lem, ch);
}
