//
// Created by Kateryna PRASOL on 13.10.2018.
//

#include "IMonitorModule.h"

Network::Network()
{
    char line[80];

    FILE *top = popen("top -l 1| grep Networks ", "r");
    fgets(line, sizeof(line), top);
    pclose(top);
    _network = line;

}
Network::Network(Network const &rhs)
{
    *this = rhs;
}
Network const & Network::operator=(Network const &rhs)
{
    if (this != &rhs)
    {
        _network = rhs._network;
    }
    return (*this);
}
Network::~Network()
{

}
std::string Network::getNetwork()
{
    char line[80];

    FILE *top = popen("top -l 1| grep Networks ", "r");
    fgets(line, sizeof(line), top);
    pclose(top);
    _network = line;
    return _network;
}

void    Network::outputNetwork(WINDOW *_winNetwork)
{
    wattron(_winNetwork, A_BOLD);
    wattron(_winNetwork, COLOR_PAIR(4));
    mvwprintw(_winNetwork, 1, 2, "%s", getNetwork().c_str());
    wattroff(_winNetwork, COLOR_PAIR(4));
    wattroff(_winNetwork, A_BOLD);
    wattron(_winNetwork, COLOR_PAIR(1));
    box(_winNetwork, 0, 0);
    wattroff(_winNetwork, COLOR_PAIR(1));
    wrefresh(_winNetwork);
}