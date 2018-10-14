//
// Created by Kateryna PRASOL on 13.10.2018.
//

#ifndef FT_GKRELLM_OSINFO_H
#define FT_GKRELLM_OSINFO_H
#include "main.h"

class OSInfo{

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
        std::string getInfo1();
        std::string getInfo2();
        std::string getInfo3();

        void   outputOSInfoWindow(WINDOW *_winOSInfo);

private:
        struct utsname _buf;
        std::string    _info1;
        std::string    _info2;
        std::string    _info3;
};


#endif //FT_GKRELLM_OSINFO_H
