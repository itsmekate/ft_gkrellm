#include <iostream>
#include "DateTime.h"
#include "Hostname.h"

int main() {
    Hostname *hn = new Hostname();
    DateTime *dt = new DateTime();

    std::cout << "Host name is: " << hn->getHostName() << std::endl;
    std::cout << "User name is: " << hn->getUserName() << std::endl;
    std::cout << "Date/Time is: " << dt->getDateTime() << std::endl;
    return 0;
}