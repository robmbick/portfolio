#include "Enemy.hpp"
#include <iostream>

Enemy::Enemy()
{
	_x = 0;
	_y = 0;
	_heights = 1;
	_width = 1;
}

Enemy::Enemy(int x, int y)
{
	_x = x;
	_y = y;
	_width = 1;
	_heights = 1;
}

Enemy::Enemy(Enemy const& obj)
{
	_x = obj._x;
	_y = obj._y;
	_width = obj._width;
	_heights = obj._heights;
}

Enemy::~Enemy()
{
}

Enemy	&Enemy::operator=(Enemy const& obj)
{
	if (this == &obj)
		return *this;
	_x = obj._x;
	_y = obj._y;
	return *this;
}

void	Enemy::set_coord(int x, int y)
{
	_x = x;
	_y = y;
}

void	Enemy::set_x(int x)
{
	_x = x;
}

void	Enemy::set_y(int y)
{
	_y = y;
}

int		Enemy::get_x() const
{
	return _x;
}

int		Enemy::get_y() const
{
	return _y;
}

int		Enemy::get_heights() const
{
	return _heights;
}

int		Enemy::get_width() const
{
	return _width;
}
