#include "Map.hpp"
// #include <ncurses.h>
#include <iostream>
int main()
{
    Map map;

    map.start();
    // initscr();                   // Переход в curses-режим
    // // cbreak();
    // curs_set(0);
    // // raw();
    // printw("Hello world!\n");  // Отображение приветствия в буфер
    // refresh();                   // Вывод приветствия на настоящий экран
    // getch();                     // Ожидание нажатия какой-либо клавиши пользователем
    // endwin();                    // Выход из curses-режима. Обязательная команда.
    //system("leaks -q a.out");
    std::cout << "\x1b[31m\n  _____          __  __ ______    ______      ________ _____  _ \n / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\| |\n| |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) | |\n| | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /| |\n| |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\|_|\n \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_(_)\n\x1b[0m" << std::endl;
    return 0;
}