//
// Created by Kateryna PRASOL on 13.10.2018.
//

#include "Ncurses.h"

Ncurses::Ncurses()
{
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    start_color();

    initwindows();
    initpairs();
    drawborders();
//    runNcurses();
}
Ncurses::Ncurses(Ncurses &rhs)
{
    *this = rhs;
}
Ncurses const & Ncurses::operator=(Ncurses & rhs)
{
    if(this != &rhs)
    {
       _winHost = rhs._winHost;
       _winNetwork = rhs._winNetwork;
       _winOSInfo = rhs._winOSInfo;
       _winCPU = rhs._winCPU;
       _winREM = rhs._winREM;
       _winCAT = rhs._winCAT;
    }
    return (*this);
}
Ncurses::~Ncurses()
{
    delwin(_winHost);
    delwin(_winNetwork);
    delwin(_winOSInfo);
    delwin(_winCPU);
    delwin(_winREM);
    delwin(_winCAT);
    endwin();
}

WINDOW *Ncurses::getHostWindow() {return _winHost;}
WINDOW *Ncurses::getWindowNetwork() {return _winNetwork;}
WINDOW *Ncurses::getWindowOSInfo() {return _winOSInfo;}
WINDOW *Ncurses::getWindowCPU() {return _winCPU;}
WINDOW *Ncurses::getWindowREM() {return _winREM;}

void Ncurses::initwindows()
{
    _winHost = newwin(5, 60, 0, 0);
    _winNetwork = newwin(5, 60, 10, 0);
    _winOSInfo = newwin(5, 60, 5, 0);
    _winCPU = newwin(5, 60, 15, 0);
    _winREM = newwin(5, 60, 20, 0);
    _winCAT = newwin(20, 60, 25, 0);
    nodelay(_winHost, true);
    nodelay(_winNetwork, true);
    nodelay(_winOSInfo, true);
    nodelay(_winCPU, true);
    nodelay(_winREM, true);
    nodelay(_winCAT, true);
}

void    Ncurses::initpairs()
{
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);
}

void    Ncurses::drawborders()
{
    wattron(_winHost, COLOR_PAIR(1));
    box(_winHost, 0, 0);
    box(_winNetwork, 0, 0);
    box(_winOSInfo, 0, 0);
    box(_winCPU, 0, 0);
    box(_winREM, 0, 0);
    box(_winCAT, 0, 0);
    wattroff(_winHost, COLOR_PAIR(1));
    wrefresh(_winHost);
    wrefresh(_winNetwork);
    wrefresh(_winOSInfo);
    wrefresh(_winCPU);
    wrefresh(_winREM);
    wrefresh(_winCAT);
}

void    Ncurses::runNcurses()
{
    Hostname *hn = new Hostname();
    DateTime *dt = new DateTime();
    OSInfo *info = new OSInfo();
    Network *n = new Network();
    CPU *cp = new CPU();
    REM *rm = new REM();
    Cat *c = new Cat();
    int i = 0;

    while(1) {
        i++;
        outputHostWindow(*dt, *hn);
        info->outputOSInfoWindow(_winOSInfo);
        n->outputNetwork(_winNetwork);
        cp->outputCPU(_winCPU);
        rm->outputREM(_winREM);
        if (i % 2 == 0)
            c->print_cat1(_winCAT);
        else
            c->print_cat2(_winCAT);
        if (wgetch(_winHost) == 'q' || wgetch(_winNetwork) == 'q' ||
            wgetch(_winOSInfo) == 'q' || wgetch(_winCPU) == 'q' ||
            wgetch(_winREM) == 'q' || wgetch(_winCAT) == 'q') {
            break;
        }
    }
//    delete hn;
//    delete dt;
//    delete info;
//    delete n;
//    delete cp;
//    delete rm;
//    delete c;
}

void    Ncurses::outputHostWindow(DateTime dt, Hostname hn)
{
    wattron(_winHost, A_BOLD);
    wattron(_winHost, COLOR_PAIR(2));
    mvwprintw(_winHost, 1, 2, "Date and Time: %s", dt.getDateTime().c_str());
    mvwprintw(_winHost, 2, 2, "Host name: %s", hn.getHostName());
    mvwprintw(_winHost, 3, 2, "User name: %s", hn.getUserName());
    wattroff(_winHost, COLOR_PAIR(2));
    wattroff(_winHost, A_BOLD);
    wattron(_winHost, COLOR_PAIR(1));
    box(_winHost, 0, 0);
    wattroff(_winHost, COLOR_PAIR(1));
    wrefresh(_winHost);
}