#pragma once

#include "Map.hpp"
#include "Bomb.hpp"

class Ship : public Bomb
{
private:
	int     _x;
	int		_y;
	int		_live;
public:
	Ship(int x, int y, int live);
	void	set_x(int x);
	void	set_y(int y);
	int		get_y() const;
	int		get_x() const;
	int		get_live() const;
	void	move_ship(int key);
	Ship	&operator=(Ship const &f);
	//void	die();
	~Ship();
};
