/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 12:32:01 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/13 12:41:51 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem		*ft_hhh_pars(char *line, t_lem *lem, int *i)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		if ((lem = ft_h_pars(line, lem, *i, 1)) == NULL || g_ch_s_en[0] == 1)
			return (NULL);
		i[0]++;
		g_ch_s_en[0] = 1;
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if ((lem = ft_h_pars(line, lem, *i, -1)) == NULL || g_ch_s_en[1] == 1)
			return (NULL);
		i[0]++;
		g_ch_s_en[1] = 1;
	}
	return (lem);
}

t_lem		*ft_hh_pars(char *line, t_lem *lem, int *i)
{
	if ((lem = pars_room(line, *i, 0, lem)) == NULL)
		return (NULL);
	if (g_lem == NULL)
		g_lem = lem;
	else
		lem = lem->next;
	i[0]++;
	return (lem);
}

int			check_command(char *line)
{
	int i;

	i = 2;
	while (line[i])
		i++;
	if (i > 6)
		if (ft_strncmp(line, "##start", 7) == 0)
		{
			ft_printf(RED"Wrong command ##start\n"RESET);
			return (0);
		}
	if (i > 4)
		if (ft_strncmp(line, "##end", 5) == 0)
		{
			ft_printf(RED"Wrong command ##end\n"RESET);
			return (0);
		}
	return (1);
}

t_lem		*ft_h_pars(char *line, t_lem *lem, int i, int k)
{
	while (get_next_line(g_fd, &line))
	{
		read_map(line);
		if (ft_strncmp(line, "##", 2) == 0)
			if (check_command(line) == 0)
				return (0);
		if (ft_strncmp(line, "#", 1) != 0)
			break ;
	}
	if (pars_line(line, 3) == 0)
		return (NULL);
	else if ((lem = pars_room(line, i, k, lem)) == NULL)
		return (NULL);
	if (g_lem == NULL)
		g_lem = lem;
	else
		lem = lem->next;
	line = NULL;
	return (lem);
}
