//
// Created by Kateryna PRASOL on 13.10.2018.
//

#include "OSInfo.h"

OSInfo::OSInfo()
{
    char line[80];
    int i = 0;

    FILE *sw_vers = popen("sw_vers", "r");
    while (fgets(line, sizeof(line), sw_vers) != NULL)
    {
        if (i == 0)
            _info1 += line;
        else if (i == 1)
            _info2 += line;
        else
            _info3 += line;
        i++;
    }
    pclose(sw_vers);

    uname(&_buf);
}
OSInfo::OSInfo(OSInfo const & rhs)
{
    *this = rhs;
}
OSInfo & OSInfo::operator=(OSInfo const &rhs)
{
    if (this != &rhs)
    {
        _buf = rhs._buf;
        _info1 = rhs._info1;
        _info2 = rhs._info2;
        _info3 = rhs._info3;
    }
    return *this;
}
OSInfo::~OSInfo()
{

}


void    OSInfo::outputOSInfoWindow(WINDOW *_winOSInfo)
{
    wattron(_winOSInfo, A_BOLD);
    wattron(_winOSInfo, COLOR_PAIR(3));
    mvwprintw(_winOSInfo, 1, 2, "%s", _info1.c_str());
    mvwprintw(_winOSInfo, 2, 2, "%s", _info2.c_str());
    mvwprintw(_winOSInfo, 3, 2, "%s", _info3.c_str());
    wattroff(_winOSInfo, COLOR_PAIR(3));
    wattroff(_winOSInfo, A_BOLD);
    wattron(_winOSInfo, COLOR_PAIR(1));
    box(_winOSInfo, 0, 0);
    wattroff(_winOSInfo, COLOR_PAIR(1));
    wrefresh(_winOSInfo);
}

void OSInfo::outputCPU(WINDOW *_winCPU){(void) _winCPU;}
void OSInfo::outputNetwork(WINDOW *_winNetwork){(void) _winNetwork;}
void OSInfo::outputREM(WINDOW *_winREM){(void) _winREM;}