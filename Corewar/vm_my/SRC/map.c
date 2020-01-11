/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:42:41 by vkuchins          #+#    #+#             */
/*   Updated: 2019/09/29 13:53:03 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	create_map(void)
{
	int		i;

	g_map = (uint8_t*)ft_memalloc(MEM_SIZE);
	i = 0;
	while (i < MEM_SIZE)
	{
		g_map[i] = 0;
		i++;
	}
}

int		get_players_count(void)
{
	t_deskriptor	*tmp;
	int				i;

	tmp = g_deskript;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	g_players_in_game = i;
	return (i);
}

void	set_players_map(void)
{
	int				players;
	int				offsets;
	t_deskriptor	*tmp;
	int				pos;
	int				i;

	players = get_players_count();
	offsets = MEM_SIZE / players;
	tmp = g_deskript;
	pos = 0;
	while (tmp)
	{
		tmp->start_pos = pos;
		i = -1;
		while (++i < tmp->bot_size)
			g_map[pos + i] = tmp->code[i];
		pos += offsets;
		tmp = tmp->next;
	}
}
