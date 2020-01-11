#include "Map.hpp"

namespace {
	void	check(EnemyManager *manager, Ship *player)
	{
		t_bomb *list;
		t_bomb *tmp;
		t_bomb *prev;
	
		list = player->get_bombs();
		tmp = list;
		while (tmp)
		{
			if (manager->try_to_hit(tmp->_x, tmp->_y) == 1)
			{
				if (list == tmp)
				list = list->next;
				else
					prev->next = tmp->next;
				delete (tmp);
				tmp = list;
				prev = NULL;
				continue ;
			}
			prev = tmp;
			tmp = tmp->next;
		}
		player->set_bombs(list);
	}
}

Map::Map(/* args */)
{
}



void Map::start()
{
	Ship player(W_map / 2, H_map, 3);
	size_t time;
	EnemyManager manager;
	size_t t = 0;

	initscr();
	noecho();
	curs_set(0);
	_map = newwin(H_map, W_map, 0, 0);
	refresh();
	this->_map_inf = newwin(H_inf, W_inf, 0, W_map);
	refresh();
	keypad(stdscr, true);
	nodelay(stdscr, TRUE); // not stop on getch
	start_color();
	init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	this->_time = clock();
	while (1)
	{
		time = clock();
		werase(this->_map); // clean window
		werase(this->_map_inf);
		this->_key = getch();
		if (this->_key == 27)
		{
			endwin();
			break ;
		}
		//player
		player.move_ship(this->_key);
		if (time - this->_time >= 30000)
		{
			player.bombs_move();
			this->_time = time;
		}
		else if (t % 1200 == 0)
			manager.force_to_dance();
		if (manager.is_alive_enemy_exists() == 0)
		{
			int enem = rand() % 50 + 1;
			manager.generate_enemies(enem);
		}
		if (manager.check_collision_with_player(player.get_x(), player.get_y()))
		{
			endwin();
			break ;
		}
		if (t % 1000 == 0)
		{
			manager.erase_enemies_which_out_of_window();
		}
		check(&manager, &player);
		wattron(this->_map_inf, COLOR_PAIR(2));
		manager.print_enemy(_map);
		wattroff(this->_map_inf, COLOR_PAIR(2));
		player.print_bombs(this->_map);
		wattron(this->_map, COLOR_PAIR(1));
		//mvwprintw(this->_map, 10, 10, "%d,  %d", player.get_x(), player.get_y());
		mvwprintw(this->_map, player.get_y() - 1, player.get_x() + 1, "^");
		mvwprintw(this->_map, player.get_y(), player.get_x(), "/ \\");
		mvwprintw(this->_map, player.get_y() + 1, player.get_x(), "| |");
		wattroff(this->_map, COLOR_PAIR(1));
		//ship
		//mvwprintw(this->_map, 0, 0,"key :%d", this->_key);
		wattron(this->_map_inf, COLOR_PAIR(2));
		mvwprintw(this->_map_inf, 0, 0, "Press ESC to exit");
		mvwprintw(this->_map_inf, 1, 0, "Press W,D,S,A to pull bombs");
		mvwprintw(this->_map_inf, 2, 0, "live : %d", player.get_live());
		wattroff(this->_map_inf, COLOR_PAIR(2));
		wrefresh(this->_map);
		wrefresh(this->_map_inf);
		t++;
	}
}

int	Map::get_key()
{
	return (this->_key);
}

Map::~Map()
{
}