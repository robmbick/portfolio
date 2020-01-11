/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:11:55 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/13 13:57:47 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		read_map(char *line)
{
	if (g_buf->str == NULL)
		g_buf->str = line;
	else
	{
		g_buf->next = (t_read*)malloc(sizeof(t_read));
		g_buf->next->str = line;
		g_buf = g_buf->next;
		g_buf->next = NULL;
	}
}

void		print_map(void)
{
	g_buf = g_buf1;
	while (g_buf != NULL)
	{
		if (g_buf->next == NULL && g_pr == 1)
			ft_printf(RED"%s\n"RESET, g_buf->str);
		else
			ft_printf("%s\n", g_buf->str);
		g_buf = g_buf->next;
	}
	ft_printf("\n");
}

int			h_pars_co(t_lem *lem2, t_lem *lem, char *line)
{
	while (lem2 != NULL)
	{
		if (lem->x == lem2->x && lem->y == lem2->y && lem != lem2)
		{
			free(line);
			return (0);
		}
		lem2 = lem2->next;
	}
	return (1);
}

t_lem		*add_list_lem(char *name, int num, int *xy, int st_end)
{
	t_lem *lem;

	lem = (t_lem*)malloc(sizeof(t_lem));
	lem->next = NULL;
	lem->link = NULL;
	lem->name = name;
	lem->num = num;
	lem->x = xy[0];
	lem->y = xy[1];
	lem->here = 0;
	lem->see = 0;
	lem->st_end = st_end;
	return (lem);
}

int			main(int argc, char **argv)
{
	g_w = 0;
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "-v") == 0)
			g_w = 1;
	}
	if ((ft_pars()) != NULL)
	{
		ft_start();
	}
	else if (g_pr != 1)
		ft_printf(RED"Map Fail\n"RESET);
	return (0);
}
