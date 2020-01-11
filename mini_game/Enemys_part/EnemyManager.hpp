#pragma once

#include <ncurses.h>
#include "../Container/Vector.hpp"
#include "Enemy.hpp"
#include "../Ship.hpp"

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();

	bool	is_alive_enemy_exists() const;

	void	generate_enemies(std::size_t count);
	void	erase_enemies_which_out_of_window();
	void	force_to_dance();
	void	print_enemy(WINDOW *window);
	bool	try_to_hit(int x, int y);
	bool	check_collision_with_player(int x, int y);

// temp | debug functions
	void	print_enemies_info() const;
private:
	vector<Enemy>	_enemies;
};
