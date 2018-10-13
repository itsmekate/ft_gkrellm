//
// Created by Kateryna PRASOL on 13.10.2018.
//

#include "Network.h"

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