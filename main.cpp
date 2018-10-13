#include <iostream>
#include "DateTime.h"
#include "Hostname.h"
#include "OSInfo.h"
#include "Network.h"
#include "Ncurses.h"

int main(int argc, char **argv)
{
    Hostname *hn = new Hostname();
    DateTime *dt = new DateTime();
    OSInfo *info = new OSInfo();
    Network *n = new Network();
    if (argc > 1)
    {
        std::string arg1(argv[1]);
        if(arg1 == "ncurses")
        {
            Ncurses *nc= new Ncurses();
            while(1)
            {
                nc->outputHostWindow(*dt, *hn);
                nc->outputOSInfoWindow(*info);
                nc->outputNetwork(*n);
            }
        }
    }
//
//    std::cout << "Host name is: " << hn->getHostName() << std::endl;
//    std::cout << "User name is: " << hn->getUserName() << std::endl;
//    std::cout << "Date/Time is: " << dt->getDateTime() << std::endl;
//    std::cout << "-------------------" << std::endl;
//    std::cout << "Sysname is : " << info->getSysname() << std::endl;
//    std::cout << "Nodename is : " << info->getNodename() << std::endl;
//    std::cout << "Release: " << info->getRelease() << std::endl;
//    std::cout << "Version: " << info->getVersion() << std::endl;
//    std::cout << "Machine: " << info->getMachine() << std::endl;
//    std::cout << "-------------------" << std::endl;
//    std::cout << "OS Info: "<<std::endl;
//    std::cout << info->getInfo() << std::endl;
//    std::cout << "-------------------" << std::endl;
//    std::cout << n->getNetwork() << std::endl;
        sleep(10);
    return 0;
}