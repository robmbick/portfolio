/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_connect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:31:37 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/13 13:56:27 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ret_link(t_lem *lem1, t_lem *lem, int x)
{
	t_lem	*lem2;
	t_link	*s;

	lem2 = lem;
	if (lem->link == NULL)
	{
		lem->link = (t_link*)malloc(sizeof(t_link));
		lem->link->next = NULL;
		while (lem1 != NULL && lem1->num != x)
			lem1 = lem1->next;
		lem->link->room = lem1;
	}
	else
	{
		s = lem->link;
		while (lem->link->next != NULL)
			lem->link = lem->link->next;
		lem->link->next = (t_link*)malloc(sizeof(t_link));
		lem->link->next->next = NULL;
		while (lem1 != NULL && lem1->num != x)
			lem1 = lem1->next;
		lem->link->next->room = lem1;
		lem->link = s;
	}
	h_ret_link(lem1, lem2);
}

static int	h_ret_found_cn(int y, int x, char *line, int i)
{
	t_lem	*lem;

	line[i] = '-';
	lem = g_lem;
	if (x == y)
	{
		ft_printf(RED"ERROR room must link in another room !\n"RESET);
		return (0);
	}
	while (lem != NULL)
	{
		if (lem->num == y)
		{
			ret_link(lem, lem, x);
			return (1);
		}
		else if (lem->num == x)
		{
			ret_link(lem, lem, y);
			return (1);
		}
		lem = lem->next;
	}
	return (1);
}

int			found_connect(char *line, t_lem *lem)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = -1;
	y = -1;
	while (line[i] != '-')
	{
		if (line[i] == '\0')
			return (0);
		i++;
	}
	line[i] = '\0';
	while (lem != NULL)
	{
		if (ft_strcmp(line, lem->name) == 0)
			x = lem->num;
		if (ft_strcmp(&line[i + 1], lem->name) == 0)
			y = lem->num;
		if (x >= 0 && y >= 0)
			return (h_ret_found_cn(y, x, line, i));
		lem = lem->next;
	}
	return (0);
}

int			read_connect(t_lem *lem, char *line)
{
	if (pars_line(line, 1) == 0)
		return (0);
	else if (found_connect(line, lem) == 0)
		return (0);
	while (get_next_line(g_fd, &line))
	{
		read_map(line);
		if (line[0] != '#')
		{
			if (pars_line(line, 1) == 0)
				return (h_rc_pars());
			if (found_connect(line, lem) == 0)
				return (h_rc_pars());
		}
		else if (ft_strncmp(line, "##", 2) == 0)
			if (check_command(line) == 0)
				return (0);
	}
	if (line != NULL)
		free(line);
	return (1);
}

t_lem		*pars_connect(t_lem *lem, char *line)
{
	t_lem	*lem1;
	t_lem	*lem2;
	int		ch[2];

	ch[0] = 0;
	ch[1] = 0;
	lem1 = lem;
	while (lem->next != NULL)
	{
		lem2 = lem1;
		(lem->st_end == 1) ? ch[0]++ : 0;
		(lem->st_end == -1) ? ch[1]++ : 0;
		if (h_pars_co(lem2, lem, line) == 0)
			return (NULL);
		lem = lem->next;
	}
	if (ch[0] != 1 || ch[1] != 1)
		return (NULL);
	if (read_connect(lem1, line) == 0)
		return (NULL);
	return (lem1);
}
