/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_bot2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 16:13:01 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/29 16:14:07 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_line_for_dump(char **argv, int ss)
{
	int		i;
	char	*line;

	i = 0;
	if (ft_strcmp(*argv, "-dump") == 0)
	{
		if (ss == 0)
		{
			ft_printf(RED"ERROR after '-dump' must be number! \
but now nothing!!\n"RESET);
			exit(1);
		}
		argv++;
		line = *argv;
		while (line[i])
			if (line[i] < '0' || line[i++] > '9')
			{
				ft_printf(RED"ERROR after '-dump' must be number!\n"RESET);
				exit(1);
			}
		g_nbr_cycles = ft_atoi(*argv);
		return (1);
	}
	return (0);
}

int		check_deskript_num(int num)
{
	t_deskriptor	*ch;

	ch = g_deskript;
	while (ch != NULL)
	{
		if (ch->num == num)
			return (0);
		ch = ch->next;
	}
	return (1);
}

void	check_str_for_cor(char *lin)
{
	char *line;

	line = lin;
	while (1)
	{
		if ((line = ft_strstr(line, ".cor")) == NULL)
		{
			ft_printf(RED"ERROR where '.cor' ????\n"RESET);
			exit(1);
		}
		if (ft_strcmp(line, ".cor") != 0)
		{
			line++;
			continue ;
		}
		break ;
	}
}

void	check_line_for_n_norm(char **argv, t_deskriptor *des)
{
	int		num;

	num = ft_atoi(*argv);
	if (num <= 0 || num > MAX_PLAYERS || check_deskript_num(num) == 0)
	{
		ft_printf(RED"ERROR incorect number after '-n'\n"RESET);
		exit(1);
	}
	argv++;
	des->name = *argv;
	check_str_for_cor(des->name);
	des->num = num;
}

int		check_line_for_n(char **argv, t_deskriptor *des, int ss)
{
	int		i;
	char	*line;

	i = -1;
	if (ft_strcmp(*argv, "-n") == 0)
	{
		if (ss == 0)
		{
			ft_printf("ERROR after '-n' must be number and player!\n");
			exit(1);
		}
		argv++;
		line = *argv;
		while (line[++i] != '\0')
			if (line[i] <= '0' || line[i] >= '9')
			{
				ft_printf(RED"ERROR after '-n' must be number \
between 1 and %i!\n"RESET, MAX_PLAYERS);
				exit(1);
			}
		check_line_for_n_norm(argv, des);
		return (1);
	}
	return (0);
}
