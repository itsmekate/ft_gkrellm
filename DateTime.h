//
// Created by Kateryna PRASOL on 13.10.2018.
//

#ifndef FT_GKRELLM_DATETIME_H
#define FT_GKRELLM_DATETIME_H
#include "IMonitorModule.h"

class DateTime : public IMonitorModule{
    private:
     std::string _dateTime;
    public:
        DateTime();
        DateTime(DateTime const & rhs);
        DateTime & operator=(DateTime const &rhs);
        ~DateTime();

        std::string getDateTime();
        void outputCPU(WINDOW *_winCPU);
        void outputNetwork(WINDOW *_winNetwork);
        void outputREM(WINDOW *_winREM);
        void outputOSInfoWindow(WINDOW *_winOSInfo);

};


#endif //FT_GKRELLM_DATETIME_H
