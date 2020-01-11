/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:42:00 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/13 13:08:28 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			pars_line(char *line, int i)
{
	int j;
	int ch;

	ch = 0;
	j = 0;
	if (line[0] == '\0' || line[0] == '\n')
		return (0);
	while (line[j])
	{
		if (line[j] == ' ')
			ch++;
		j++;
	}
	if (line[j - 1] == ' ')
	{
		ft_printf(RED"Wrong number of coordinate !\n"RESET);
		return (0);
	}
	if (ch != i - 1)
		return (0);
	return (1);
}

static int	h_pars_room(int i, char *line, char *name)
{
	i++;
	while (line[i] != ' ')
	{
		if (line[i] != '-' && line[i] != '+')
		{
			if (line[i] < '0' || line[i] > '9')
			{
				free(name);
				return (-1);
			}
		}
		i++;
	}
	i++;
	return (i);
}

t_lem		*pars_room(char *line, int num, int st_end, t_lem *lem)
{
	int		xy[2];
	int		i;
	char	*name;

	i = 0;
	while (line[i] != ' ')
		i++;
	name = (ft_strncpy((char*)malloc(sizeof(char) * (i + 1)), line, i));
	name[i] = '\0';
	xy[0] = ft_atoi(&line[i]);
	if ((i = h_pars_room(i, line, name)) == -1)
		return (NULL);
	xy[1] = ft_atoi(&line[i]);
	while (line[i])
	{
		if (line[i] < '0' || line[i] > '9')
		{
			free(name);
			return (NULL);
		}
		i++;
	}
	(g_lem == NULL) ? lem = (add_list_lem(name, num, xy, st_end)) : 0;
	(g_lem != NULL) ? lem->next = (add_list_lem(name, num, xy, st_end)) : 0;
	return (lem);
}

t_lem		*h_pars(char *line, t_lem *lem)
{
	int		i;

	i = 0;
	g_lem = lem;
	while (get_next_line(g_fd, &line))
	{
		read_map(line);
		if (line[0] == '#')
		{
			if ((ft_strcmp(line, "##end") == 0) ||
				(ft_strcmp(line, "##start") == 0))
				if ((lem = ft_hhh_pars(line, lem, &i)) == NULL)
					return (NULL);
		}
		else
		{
			if (norm_pars(line) == 0)
				return (NULL);
			if (norm_pars(line) == 1)
				break ;
			else if ((lem = ft_hh_pars(line, lem, &i)) == NULL)
				return (NULL);
		}
	}
	return (g_lem);
}

t_lem		*ft_pars(void)
{
	char	*line;

	ini_ft_pars();
	while (get_next_line(g_fd, &line))
	{
		read_map(line);
		if (line == NULL || *line == '\0')
			return (NULL);
		else if (ft_strncmp(line, "##", 2) == 0)
			return (NULL);
		else if (ft_strncmp(line, "#", 1) == 0)
			continue;
		if (remb(line) == 0)
			return (NULL);
		break ;
	}
	if (line == NULL)
		return (NULL);
	if (((g_ants = ft_atoi(line)) <= 0) || (pars_line(line, 1)) == 0)
		return (NULL);
	if (g_ants < 1)
		return (NULL);
	if ((h_pars(line, g_lem)) == NULL)
		return (NULL);
	return (g_lem);
}
