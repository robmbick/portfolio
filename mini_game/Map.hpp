#ifndef MAP_HPP
# define MAP_HPP

# include "stdlib.h"
# include <ncurses.h>
# include "Enemys_part/EnemyManager.hpp"
# include "Ship.hpp"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

# define H_map 70
# define W_map 180
# define H_inf 70
# define W_inf 40


class Map
{
private:
    WINDOW	*_map;
    WINDOW	*_map_inf;
    int		_key;
    int     _time;
public:
    Map(/* args */);
    void    start();
	int		get_key();
    ~Map();
};
#endif