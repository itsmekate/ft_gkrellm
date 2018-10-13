//
// Created by Kateryna PRASOL on 13.10.2018.
//

#ifndef FT_GKRELLM_OSINFO_H
#define FT_GKRELLM_OSINFO_H
#include <iostream>
#include <string>
#include <sys/utsname.h>

class OSInfo {

    public:
        OSInfo();
        OSInfo(OSInfo const & rhs);
        OSInfo & operator=(OSInfo const &rhs);
        ~OSInfo();

        std::string getSysname();
        std::string getNodename();
        std::string getRelease();
        std::string getVersion();
        std::string getMachine();
        std::string getInfo();

private:
        struct utsname _buf;
        std::string    _info;

};


#endif //FT_GKRELLM_OSINFO_H
