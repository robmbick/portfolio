#include "Ship.hpp"

Ship::Ship(int x, int y, int live) : Bomb(), _x(x), _y(y), _live(live)
{
}

Ship &Ship::operator= (Ship const &f)
{
	this->_live = f._live;
	this->_x = f._x;
	this->_y = f._y;
	return (*this);
}

void	Ship::move_ship(int	key)
{
	if (key == 119)
		this->create_bomb(this->_x + 1, this->_y - 1, 1);
	else if (key == 115)
		this->create_bomb(this->_x + 1, this->_y, 2);
	else if (key == 100)
		this->create_bomb(this->_x, this->_y, 3);
	else if (key == 97)
		this->create_bomb(this->_x, this->_y, 4);
	if (key == 259)
		this->_y--;
	else if (key == 258)
		this->_y++;
	else if (key == 261)
		this->_x+=2;
	else if (key == 260)
		this->_x-=2;
	if (this->_x > W_map - 3)
		this->_x = W_map - 3;
	else if (this->_x < 0)
		this->_x = 0;
	if (this->_y > H_map - 2)
		this->_y = H_map - 2;
	else if (this->_y < 1)
		this->_y = 1;
}

int		Ship::get_live() const
{
	return (this->_live);
}

int     Ship::get_x() const
{
    return (this->_x);
}

int     Ship::get_y() const
{
    return (this->_y);
}

void    Ship::set_x(int x)
{
    this->_x = x;
}

void    Ship::set_y(int y)
{
    this->_y = y;
}

Ship::~Ship()
{

}