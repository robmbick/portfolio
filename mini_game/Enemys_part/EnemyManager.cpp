#include "EnemyManager.hpp"
#include "../Map.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

namespace {
	bool	check_collision(Enemy const& ship, int x, int y)
	{
		return (ship.get_x() == x && ship.get_y() == y);
	}
}

EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}

bool	EnemyManager::is_alive_enemy_exists() const
{
	return !_enemies.empty();
}

void	EnemyManager::generate_enemies(std::size_t count)
{
	for (std::size_t i = 0; i < count; ++i)
	{
		srand(time(NULL) + i);
		_enemies.push_back(Enemy(rand() % W_map, rand() % H_map));
	}
}

void	EnemyManager::erase_enemies_which_out_of_window()
{
	for (std::size_t i = 0; i < _enemies.size(); ++i)
	{
		if (_enemies[i].get_y() >= H_map)
		{
			_enemies.erase(i);
			continue;
		}
	}
}

void	EnemyManager::force_to_dance()
{
	static std::size_t count_of_calls = 0;
	std::size_t enemies_count = _enemies.size();

	int step = (count_of_calls % 2 ? 1 : -1);

	for (std::size_t i = 0; i < enemies_count; ++i)
	{
		_enemies[i].set_coord(_enemies[i].get_x() + step, _enemies[i].get_y() + 1);
	}

	++count_of_calls;
}

void	EnemyManager::print_enemy(WINDOW *window)
{
	std::size_t enemies_count = _enemies.size();
	for (std::size_t i = 0; i < enemies_count; ++i)
	{
		mvwprintw(window, _enemies[i].get_y(), _enemies[i].get_x(), "@");
	}
}

bool	EnemyManager::try_to_hit(int x, int y)
{
	std::size_t count_of_enemies = _enemies.size();

	for (std::size_t i = 0; i < count_of_enemies; ++i)
	{
		if (check_collision(_enemies[i], x, y))
		{
			_enemies.erase(i);
			return true;
		}
	}
	return false;

}

bool	EnemyManager::check_collision_with_player(int x, int y)
{
	if (try_to_hit(x + 1, y + 1) || try_to_hit(x - 1, y - 1) || try_to_hit(x - 1, y) || try_to_hit(x, y - 1))
		return true;
	return false;
}

void	EnemyManager::print_enemies_info() const
{
	std::size_t enemies_count = _enemies.size();
	for (std::size_t i = 0; i < enemies_count; ++i)
	{
		std::cout << "coord: " << _enemies[i].get_x() << '\t' << _enemies[i].get_y() << std::endl;
	}
}
