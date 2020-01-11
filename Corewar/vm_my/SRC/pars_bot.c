/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_bot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:41:07 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/29 19:11:02 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	record_name(char *name, t_deskriptor *des)
{
	int		i;

	i = 0;
	check_str_for_cor(name);
	des->name = name;
	while (++i <= MAX_PLAYERS + 1)
	{
		if (check_deskript_num(i) == 1)
		{
			g_kostul = des;
			des->num = 0;
			des->next = (t_deskriptor*)malloc(sizeof(t_deskriptor));
			des->next->next = NULL;
			return ;
		}
	}
	ft_printf(RED"ERROR number of player is %i\n"RESET, MAX_PLAYERS);
	exit(1);
}

void	numer_deskript(void)
{
	t_deskriptor	*des;
	int				i;

	des = g_deskript;
	while (des != NULL)
	{
		des->live = 0;
		if (des->num == 0)
		{
			i = 0;
			while (++i <= MAX_PLAYERS + 1)
				if (check_deskript_num(i) == 1)
				{
					des->num = i;
					break ;
				}
			if (des->num == 0)
			{
				ft_printf(RED"ERROR number of player is %i\n"RESET,
													MAX_PLAYERS);
				exit(1);
			}
		}
		des = des->next;
	}
}

void	check_for_err_in_v(char **argv)
{
	char	*line;
	int		i;

	i = 0;
	line = *argv;
	while (line[i])
		if (line[i] < '0' || line[i++] > '9')
		{
			ft_printf(RED"ERROR after '-v' must be number!\n"RESET);
			exit(1);
		}
}

void	pars_bot_c(int argc, char **argv, t_deskriptor *des, int i)
{
	while (++i < argc)
	{
		if (check_line_for_n(&argv[i], des, (i + 2 >= argc) ? 0 : 1) == 1)
		{
			g_kostul = des;
			des->next = (t_deskriptor*)malloc(sizeof(t_deskriptor));
			des = des->next;
			des->next = NULL;
			i = i + 2;
		}
		else if (ft_strcmp(argv[i], "-p") == 0 && argv[i + 1])
			g_visual = 1;
		else if (check_line_for_dump(&argv[i], (i + 1 >= argc) ? 0 : 1) == 1)
			i++;
		else if (ft_strcmp(argv[i], "-v") == 0 && argv[i + 1] && argv[i + 2])
		{
			g_print = ft_atoi(argv[++i]);
			check_for_err_in_v(&argv[i]);
		}
		else
		{
			record_name(argv[i], des);
			des = des->next;
		}
	}
}

int		pars_bot(int argc, char **argv)
{
	t_deskriptor	*des;

	g_visual = 0;
	g_kostul = NULL;
	g_deskript = (t_deskriptor*)malloc(sizeof(t_deskriptor));
	g_deskript->num = 0;
	g_deskript->next = NULL;
	des = g_deskript;
	pars_bot_c(argc, argv, des, 0);
	if (g_kostul != NULL)
	{
		free(g_kostul->next);
		g_kostul->next = NULL;
		numer_deskript();
		check_file();
	}
	return (1);
}
