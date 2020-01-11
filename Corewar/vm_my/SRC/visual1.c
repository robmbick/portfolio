/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <vpalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:05:44 by vpalamar          #+#    #+#             */
/*   Updated: 2019/09/29 20:11:46 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_winner_vs(void)
{
	t_deskriptor	*tmp;

	tmp = g_deskript;
	while (tmp)
	{
		if (tmp->num == g_last_player_live)
			break ;
		tmp = tmp->next;
	}
	wattron(g_win_tab, A_BOLD | COLOR_PAIR(tmp->num));
	if (tmp)
		mvwprintw(g_win_tab, 35, 10, "Winner is %d %s",
							tmp->num, tmp->name_bot);
	else
		mvwprintw(g_win_tab, 35, 10, "No one sayed live");
	wattroff(g_win_tab, A_BOLD | COLOR_PAIR(tmp->num));
}

void	init_vm(t_tab *tab)
{
	g_last_check = 0;
	g_cycle = 1;
	g_cycle_to_die = CYCLE_TO_DIE;
	g_live_in_curent_cycle = 0;
	initscr();
	curs_set(0);
	start_color();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	noecho();
	g_win_map = newwin(MEM_SIZE / 64 + 2, 64 * 3 + 3, 1, 2);
	g_win_tab = newwin(MEM_SIZE / 64 + 2, 60, 1, 64 * 3 + 8);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_GREEN);
	init_pair(6, COLOR_WHITE, COLOR_BLUE);
	init_pair(7, COLOR_WHITE, COLOR_RED);
	init_pair(8, COLOR_WHITE, COLOR_CYAN);
	tab_init(tab);
}

void	cycle_vm_norm(t_tab *tab)
{
	werase(g_win_tab);
	werase(g_win_map);
	box(g_win_map, 0, 0);
	box(g_win_tab, 0, 0);
	tab_info_print(tab);
	first_print_tab(tab);
	map_win_refresh(-1);
	map_win_car(-1, 1, 1, g_carriages);
}

void	cycle_vm(int max_check, t_tab tab, int key)
{
	init_vm(&tab);
	tab.offset = 0;
	while ((key = getch()) != 10)
	{
		if (key && key_hook(&tab, key))
			break ;
		cycle_vm_norm(&tab);
		if (tab.is_running && clock() >= get_last_time(&tab))
		{
			carriage_one_cycle();
			if ((g_cycle_to_die < 0 || ((g_cycle - g_last_check)
										% g_cycle_to_die == 0 &&
				cycle_die(&max_check, g_cycle) == 0)))
				print_winner_vs();
			else
				g_cycle++;
			if ((g_nbr_cycles != 0 && g_nbr_cycles == g_cycle))
				print_map();
			tab.offset = clock();
		}
		wrefresh(g_win_map);
		wrefresh(g_win_tab);
	}
	endwin();
	exit(1);
}
