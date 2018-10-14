//
// Created by Kateryna PRASOL on 13.10.2018.
//

#ifndef FT_GKRELLM_OSINFO_H
#define FT_GKRELLM_OSINFO_H
#include <string>
#include "Ncurses.h"
#include "IMonitorModule.h"

class OSInfo : public IMonitorModule{

    public:
        OSInfo();
        OSInfo(OSInfo const & rhs);
        OSInfo & operator=(OSInfo const &rhs);
        ~OSInfo();

        void   outputOSInfoWindow(WINDOW *_winOSInfo);

private:
        struct utsname _buf;
        std::string    _info1;
        std::string    _info2;
        std::string    _info3;
};


#endif //FT_GKRELLM_OSINFO_H
