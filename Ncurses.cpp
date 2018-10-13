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
    runNcurses();
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
    _winCAT = newwin(15, 60, 25, 0);
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

    while(1)
    {
        outputHostWindow(*dt, *hn);
        outputOSInfoWindow(*info);
        outputNetwork(*n);
        outputCPU(*cp);
        outputREM(*rm);
        outputCAT();
//        if (getch() == 'q')
//            exit(1);
    }
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

void    Ncurses::outputOSInfoWindow(OSInfo info)
{
    wattron(_winOSInfo, A_BOLD);
    wattron(_winOSInfo, COLOR_PAIR(3));
    mvwprintw(_winOSInfo, 1, 2, "%s", info.getInfo1().c_str());
    mvwprintw(_winOSInfo, 2, 2, "%s", info.getInfo2().c_str());
    mvwprintw(_winOSInfo, 3, 2, "%s", info.getInfo3().c_str());
    wattroff(_winOSInfo, COLOR_PAIR(3));
    wattroff(_winOSInfo, A_BOLD);
    wattron(_winOSInfo, COLOR_PAIR(1));
    box(_winOSInfo, 0, 0);
    wattroff(_winOSInfo, COLOR_PAIR(1));
    wrefresh(_winOSInfo);
}

void    Ncurses::outputNetwork(Network n)
{
    wattron(_winNetwork, A_BOLD);
    wattron(_winNetwork, COLOR_PAIR(4));
    mvwprintw(_winNetwork, 1, 2, "%s", n.getNetwork().c_str());
    wattroff(_winNetwork, COLOR_PAIR(4));
    wattroff(_winNetwork, A_BOLD);
    wattron(_winNetwork, COLOR_PAIR(1));
    box(_winNetwork, 0, 0);
    wattroff(_winNetwork, COLOR_PAIR(1));
    wrefresh(_winNetwork);
}

void Ncurses::outputCPU(CPU cp)
{
    wattron(_winCPU, A_BOLD);
    wattron(_winCPU, COLOR_PAIR(5));
    mvwprintw(_winCPU, 1, 2, "%s", cp.getCPU().c_str());
    wattroff(_winCPU, COLOR_PAIR(5));
    wattroff(_winCPU, A_BOLD);
    wattron(_winCPU, COLOR_PAIR(1));
    box(_winCPU, 0, 0);
    wattroff(_winCPU, COLOR_PAIR(1));
    wrefresh(_winCPU);
}


void Ncurses::outputREM(REM rm)
{
    wattron(_winREM, A_BOLD);
    wattron(_winREM, COLOR_PAIR(6));
    mvwprintw(_winREM, 1, 2, "%s", rm.getREM().c_str());
    wattroff(_winREM, COLOR_PAIR(6));
    wattroff(_winREM, A_BOLD);
    wattron(_winREM, COLOR_PAIR(1));
    box(_winREM, 0, 0);
    wattroff(_winREM, COLOR_PAIR(1));
    wrefresh(_winREM);
}

void Ncurses::outputCAT()
{
    wattron(_winCAT, A_BOLD);
    wattron(_winCAT, COLOR_PAIR(6));
    mvwprintw(_winCAT, 1, 2, "       (`.");
    mvwprintw(_winCAT, 2, 2, "         ) )");
    mvwprintw(_winCAT, 3, 2, "        ( (");
    mvwprintw(_winCAT, 4, 2, "         \\ \\");
    mvwprintw(_winCAT, 5, 2, "          \\ \\");
    mvwprintw(_winCAT, 6, 2, "        .-'  `-.");
    mvwprintw(_winCAT, 7, 2, "       /        `.");
    mvwprintw(_winCAT, 8, 2, "      (      )    `-._ , ");
    mvwprintw(_winCAT, 9, 2, "       )   ,'         (.\\--'(");
    mvwprintw(_winCAT, 10, 2, "       \\  (         ) /      \\");
    mvwprintw(_winCAT, 11, 2, "        \\  \\_(     / (    <6 (6");
    mvwprintw(_winCAT, 12, 2, "         \\_)))\\   (   `._  .:Y)__");
    mvwprintw(_winCAT, 13, 2, "          '''  \\   `-._.'`---^_)))");
    mvwprintw(_winCAT, 14, 2, "                `-._ )))       ```");
    mvwprintw(_winCAT, 15, 2, "                    ```           hjw");
    wattroff(_winCAT, COLOR_PAIR(6));
    wattroff(_winCAT, A_BOLD);
    wattron(_winCAT, COLOR_PAIR(1));
    box(_winCAT, 0, 0);
    wattroff(_winCAT, COLOR_PAIR(1));
    wrefresh(_winCAT);
}