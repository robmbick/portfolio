/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_ft_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:41:20 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/13 13:58:45 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		h_ret_link(t_lem *lem1, t_lem *lem2)
{
	t_link	*s;

	if (lem1->link == NULL)
	{
		lem1->link = (t_link*)malloc(sizeof(t_link));
		lem1->link->room = lem2;
		lem1->link->next = NULL;
	}
	else
	{
		s = lem1->link;
		while (lem1->link->next != NULL)
			lem1->link = lem1->link->next;
		lem1->link->next = (t_link*)malloc(sizeof(t_link));
		lem1->link->next->room = lem2;
		lem1->link->next->next = NULL;
		lem1->link = s;
	}
}

int			norm_pars(char *line)
{
	if (pars_line(line, 3) == 0)
	{
		if (g_ch_s_en[0] == 0 || g_ch_s_en[1] == 0)
			return (0);
		if (pars_connect(g_lem, line) == NULL)
			return (0);
		return (1);
	}
	return (2);
}

int			h_rc_pars(void)
{
	ft_printf(RED"Problem in link, try start ...\n"RESET);
	g_pr = 1;
	ft_start();
	return (0);
}

void		ini_ft_pars(void)
{
	g_pr = 0;
	g_ch_s_en[0] = 0;
	g_ch_s_en[1] = 0;
	g_lem = NULL;
	g_ants = -1;
	g_fd = 0;
	g_buf = (t_read*)malloc(sizeof(t_read));
	g_buf->str = NULL;
	g_buf1 = g_buf;
}

int			remb(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '+' && (line[i] < '0' || line[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}
