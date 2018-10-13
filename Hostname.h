//
// Created by Kateryna PRASOL on 13.10.2018.
//

#ifndef FT_GKRELLM_HOSTNAME_H
#define FT_GKRELLM_HOSTNAME_H
#include <unistd.h>
#include <limits.h>

class Hostname {
    public:
    Hostname();
    Hostname(Hostname const & rhs);
//    Hostname & operator=(Hostname const &rhs);
    ~Hostname();

    char* getHostName();
    char* getUserName();

    private:
        char _hostname[20];
        char _username[20];
};


#endif //FT_GKRELLM_HOSTNAME_H
