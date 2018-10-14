//
// Created by Kateryna PRASOL on 13.10.2018.
//

#include "REM.h"

REM::REM()
{
    char line[80];

    FILE *top = popen("top -l 1| grep PhysMem", "r");
    fgets(line, sizeof(line), top);
    pclose(top);
    _REM = line;

}
REM::REM(REM const &rhs)
{
    *this = rhs;
}
REM const & REM::operator=(REM const &rhs)
{
    if (this != &rhs)
    {
        _REM = rhs._REM;
    }
    return (*this);
}
REM::~REM()
{

}
std::string REM::getREM()
{
    char line[80];

    FILE *top = popen("top -l 1| grep PhysMem", "r");
    fgets(line, sizeof(line), top);
    pclose(top);
    _REM = line;
    return _REM;
}


void REM::outputREM(WINDOW *_winREM)
{

    std::string s = getREM();
    int d = stoi(s.substr(9, 11)) / 400;
    std::string progress (d, ' ');

    wattron(_winREM, COLOR_PAIR(7));
    mvwprintw(_winREM, 3, 2, "..............................................");
    wattron(_winREM, COLOR_PAIR(7));


    wattron(_winREM, A_BOLD);
    wattron(_winREM, COLOR_PAIR(6));
    mvwprintw(_winREM, 1, 2, "%s", getREM().c_str());
    wattroff(_winREM, COLOR_PAIR(6));

    wattron(_winREM, COLOR_PAIR(10));
    mvwprintw(_winREM, 3, 2, "%s", progress.c_str());
    wattroff(_winREM, COLOR_PAIR(10));

    wattroff(_winREM, A_BOLD);
    wattron(_winREM, COLOR_PAIR(1));
    box(_winREM, 0, 0);
    wattroff(_winREM, COLOR_PAIR(1));
    wrefresh(_winREM);
}

void REM::outputCPU(WINDOW *_winCPU){(void)_winCPU;}
void REM::outputNetwork(WINDOW *_winNetwork){(void) _winNetwork;}
void REM::outputOSInfoWindow(WINDOW *_winOSInfo){(void) _winOSInfo;}