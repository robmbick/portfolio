/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuchins <vkuchins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:46:34 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/28 18:03:58 by vkuchins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		check_open2(t_deskriptor *des)
{
	char	buf;

	if ((des->bot_size = read_magic_header(des->fd)) < 0)
	{
		ft_printf(RED"ERROR BAD BOT SIZE\n"RESET);
		exit(1);
	}
	if (des->bot_size > CHAMP_MAX_SIZE)
	{
		ft_printf(RED"ERROR BOT CODE (%d) TO BIG \n"RESET, des->num);
		exit(1);
	}
	read_comment(des);
	if (read_magic_header(des->fd) != 0)
	{
		ft_printf(RED"ERROR NOT NULL AFTER COMMENT \n"RESET);
		exit(1);
	}
	read_code(des);
	if (read(des->fd, &buf, 1) != 0)
	{
		ft_printf(RED"ERROR BAD DATA ON END FILE \n"RESET);
		exit(1);
	}
	close(des->fd);
}

void		check_open(t_deskriptor *des)
{
	if ((des->fd = open(des->name, O_RDONLY)) < 0)
	{
		ft_printf(RED"ERROR not found %s\n"RESET, des->name);
		exit(1);
	}
	if (read_magic_header(des->fd) != COREWAR_EXEC_MAGIC)
	{
		ft_printf(RED"ERROR INVALID MAGIC HEADER \n"RESET);
		exit(1);
	}
	read_name(des);
	if (read_magic_header(des->fd) != 0)
	{
		ft_printf(RED"ERROR NOT NULL AFTER BOT NAME \n"RESET);
		exit(1);
	}
	check_open2(des);
}

void		sort_list(void)
{
	t_deskriptor	*tmp;
	t_deskriptor	*prev;
	t_deskriptor	*work;

	prev = NULL;
	work = g_deskript;
	while (work->next)
	{
		if (work->num > work->next->num)
		{
			tmp = work->next;
			if (prev == NULL)
				g_deskript = g_deskript->next;
			else
				prev->next = work->next;
			work->next = work->next->next;
			tmp->next = work;
			prev = NULL;
			work = g_deskript;
			continue;
		}
		prev = work;
		work = work->next;
	}
}

void		check_num(t_deskriptor *des)
{
	int		i;

	i = 1;
	while (des != NULL)
	{
		g_last_player_live = des->num;
		if (des->num != i)
		{
			ft_printf(RED"ERROR BAD PLAYER IN -n\n"RESET);
			exit(1);
		}
		des = des->next;
		i++;
	}
}

void		check_file(void)
{
	t_deskriptor	*des;

	sort_list();
	check_num(g_deskript);
	des = g_deskript;
	while (des != NULL)
	{
		check_open(des);
		des = des->next;
	}
}
