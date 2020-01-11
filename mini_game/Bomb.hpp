#ifndef BOMB_HPP
# define BOMB_HPP

#include <ncurses.h>
#include <iostream>

typedef struct  s_bomb
{
    int _move;
    int _x;
    int _y;
    struct s_bomb *next;
}       t_bomb;

class Bomb
{
private:
    t_bomb *_bombs;
public:
    Bomb();
    t_bomb    *get_bombs();
    void      set_bombs(t_bomb *s);
    void    create_bomb(int x, int y, int move);
    void	bombs_move();
	void	print_bombs(WINDOW *window);
    virtual ~Bomb();
};

#endif