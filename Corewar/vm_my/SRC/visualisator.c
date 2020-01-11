/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <vpalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:04:14 by vpalamar          #+#    #+#             */
/*   Updated: 2019/09/29 20:07:28 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	tab_info_print(t_tab *tab)
{
	int	y;
	int	x;

	x = 4;
	y = 2;
	wattron(g_win_tab, A_BOLD);
	mvwprintw(g_win_tab, y + 1, x + 22, "%4u%%", tab->cycles_per_sec);
	mvwprintw(g_win_tab, y + 3, x + 8, "%18u", g_cycle);
	mvwprintw(g_win_tab, y + 5, x + 12, "%14u", g_carriages_alive);
	y = tab->y;
	mvwprintw(g_win_tab, y + 1, x + 15, "%5u", g_cycle_to_die);
	mvwprintw(g_win_tab, y + 3, x + 14, "%6u", CYCLE_DELTA);
	mvwprintw(g_win_tab, y + 5, x + 11, "%9u", NBR_LIVE);
	mvwprintw(g_win_tab, y + 7, x + 13, "%7u", MAX_CHECKS);
	wattroff(g_win_tab, A_BOLD);
}

void	first_print_player(int x, int *y)
{
	int				nbr_player;
	t_deskriptor	*tmp;

	tmp = g_deskript;
	(*y)++;
	nbr_player = -1;
	while (tmp)
	{
		wattron(g_win_tab, A_BOLD);
		mvwprintw(g_win_tab, *y, x, "Player %d : ", tmp->num);
		wattron(g_win_tab, A_BOLD | COLOR_PAIR(tmp->num));
		mvwprintw(g_win_tab, *y, x + 12, "%s", tmp->name_bot);
		wattroff(g_win_tab, A_BOLD | COLOR_PAIR(tmp->num));
		*y += 1;
		mvwprintw(g_win_tab, *y, x + 2, "Lives in current \
period :  %d", tmp->live);
		nbr_player--;
		*y += 2;
		tmp = tmp->next;
	}
}

void	first_print_tab(t_tab *tab)
{
	int			x;
	int			y;

	x = 4;
	y = 1;
	wattron(g_win_tab, A_BOLD);
	if (tab->is_running)
		mvwprintw(g_win_tab, y, 20, "** RUNNING **");
	else
		mvwprintw(g_win_tab, y, 20, "** PAUSED **");
	y += 1;
	mvwprintw(g_win_tab, y + 1, x, "Speed limit : ");
	mvwprintw(g_win_tab, y + 3, x, "Cycle : ");
	mvwprintw(g_win_tab, y + 5, x, "Processes : ");
	y += 8;
	first_print_player(x, &y);
	wattron(g_win_tab, A_BOLD);
	y++;
	tab->y = y;
	mvwprintw(g_win_tab, y + 1, x, "CYCLE_TO_DIE : ");
	mvwprintw(g_win_tab, y + 3, x, "CYCLE_DELTA : ");
	mvwprintw(g_win_tab, y + 5, x, "NBR_LIVE : ");
	mvwprintw(g_win_tab, y + 7, x, "MAX_CHECKS : ");
	wattroff(g_win_tab, A_BOLD);
}

void	change_speed(t_tab *tab, int off)
{
	if (tab->cycles_per_sec + off > 100)
		tab->cycles_per_sec = 100;
	else if (tab->cycles_per_sec + off <= 0)
		tab->cycles_per_sec = 1;
	else
		tab->cycles_per_sec += off;
}

bool	key_hook(t_tab *tab, int key)
{
	if (key == 32)
		tab->is_running = (tab->is_running) ? 0 : 1;
	else if (key == 10)
		return (1);
	else if (key == 'q')
		change_speed(tab, 1);
	else if (key == 'a')
		change_speed(tab, -1);
	else if (key == 'w')
		change_speed(tab, 10);
	else if (key == 's')
		change_speed(tab, -10);
	return (0);
}
