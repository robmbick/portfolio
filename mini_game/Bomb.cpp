#include "Bomb.hpp"
#include <iostream>

Bomb::Bomb() : _bombs(NULL)
{
}

void       Bomb::create_bomb(int x,int y,int move)
{
    if (_bombs == NULL)
    {
        _bombs = new t_bomb;
        _bombs->next = NULL;
        _bombs->_move = move;
        _bombs->_x = x; 
        _bombs->_y = y;
    }
    else
    {
        t_bomb *tmp = _bombs;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new t_bomb;
        tmp->next->next = NULL;
        tmp->next->_move = move;
        tmp->next->_x = x; 
        tmp->next->_y = y;
    }
}

void		Bomb::bombs_move()
{
    for (t_bomb *tmp = _bombs; tmp != NULL; tmp = tmp->next)
    {
        switch (tmp->_move)
        {
        case 1:
            tmp->_y--;
            break ;
        case 2:
            tmp->_y++;
            break ;
        case 3:
            tmp->_x++;
            break ;
        case 4:
            tmp->_x--;
            break ;
        default:
            break;
        }
    }
}

void		Bomb::print_bombs(WINDOW *window)
{
	for (t_bomb *tmp = _bombs; tmp != NULL; tmp = tmp->next)
    {
		mvwprintw(window, tmp->_y, tmp->_x, "*");
	}
}

t_bomb      *Bomb::get_bombs()
{
    return (this->_bombs);
}

void        Bomb::set_bombs(t_bomb *s)
{
    _bombs = s;
}

Bomb::~Bomb()
{
    t_bomb *tmp;

    while (_bombs != NULL)
    {
        tmp = _bombs;
        _bombs = _bombs->next;
        delete tmp;
    }
}