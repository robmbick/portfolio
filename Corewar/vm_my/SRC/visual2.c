/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <vpalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:11:20 by vpalamar          #+#    #+#             */
/*   Updated: 2019/09/29 20:14:08 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_tab	*tab_init(t_tab *tab)
{
	tab->is_running = 0;
	tab->cycles_per_sec = 1;
	return (tab);
}

clock_t	get_last_time(t_tab *tab)
{
	return (tab->offset + CLOCKS_PER_SEC / tab->cycles_per_sec / 100);
}

void	map_win_car(int i, int y, int x, t_carriage *car)
{
	while (++i < MEM_SIZE)
	{
		while (car)
		{
			if (car->i == i)
			{
				wattron(g_win_map, A_BOLD | COLOR_PAIR(car->own + 4));
				break ;
			}
			car = car->next;
		}
		if (car)
			mvwprintw(g_win_map, y, x, " %.2x", g_map[i]);
		x += 3;
		if (x >= 64 * 3)
		{
			x = 1;
			y++;
		}
		if (car)
			wattroff(g_win_map, A_BOLD | COLOR_PAIR(car->own + 4));
		car = g_carriages;
	}
}

void	map_win_refresh(int i)
{
	int				y;
	int				x;
	t_deskriptor	*tmp;

	tmp = g_deskript;
	y = 1;
	x = 1;
	while (++i < MEM_SIZE)
	{
		if (tmp && i == tmp->start_pos)
			wattron(g_win_map, A_BOLD | COLOR_PAIR(tmp->num));
		mvwprintw(g_win_map, y, x, " %.2x", g_map[i]);
		x += 3;
		if (x >= 64 * 3)
		{
			x = 1;
			y++;
		}
		if (tmp && i == tmp->start_pos + tmp->bot_size)
		{
			wattroff(g_win_map, A_BOLD | COLOR_PAIR(tmp->num));
			tmp = tmp->next;
		}
	}
}
