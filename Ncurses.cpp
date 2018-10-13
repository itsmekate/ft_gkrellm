//
// Created by Kateryna PRASOL on 13.10.2018.
//

#include "Ncurses.h"

Ncurses::Ncurses()
{
    initscr();
    clear();
    noecho();
//    cbreak();
//    keypad(stdscr, TRUE);
    curs_set(FALSE);
    start_color();

    _win = newwin(50, 120, 0, 0);
        init_pair(1, COLOR_WHITE, COLOR_WHITE);
        wattron(_win, COLOR_PAIR(1));
        box(_win, 0, 0);
        wattroff(_win, COLOR_PAIR(1));
        wrefresh(_win);
//    }

    sleep(10);
    nodelay(_win, true);
}
Ncurses::Ncurses(Ncurses &rhs)
{
    *this = rhs;
}
Ncurses const & Ncurses::operator=(Ncurses & rhs)
{
    if(this != &rhs)
    {
        _win = rhs._win;
    }
    return (*this);
}
Ncurses::~Ncurses()
{
    delwin(_win);
    endwin();
}

WINDOW *Ncurses::getWindow() {return _win;}
//
//void Ncurses::draw_borders(WINDOW *screen)
//{
//    int x, y, i;
//    getmaxyx(screen, y, x);
//    mvwprintw(screen, 0, 0, "+");
//    mvwprintw(screen, y - 1, 0, "+");
//    mvwprintw(screen, 0, x - 1, "+");
//    mvwprintw(screen, y - 1, x - 1, "+");
//    for (i = 1; i < (y - 1); i++)
//    {
//        mvwprintw(screen, i, 0, "|");
//        mvwprintw(screen, i, x - 1, "|");
//    }
//    for (i = 1; i < (x - 1); i++)
//    {
//        mvwprintw(screen, 0, i, "-");
//        mvwprintw(screen, y - 1, i, "-");
//    }
//}