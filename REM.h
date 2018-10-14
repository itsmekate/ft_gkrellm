//
// Created by Kateryna PRASOL on 13.10.2018.
//

#ifndef FT_GKRELLM_REM_H
#define FT_GKRELLM_REM_H
#include "IMonitorModule.h"

class REM : public IMonitorModule{
    public:
        REM();
        REM(REM const &rhs);
        REM const & operator=(REM const &rhs);
        ~REM();
        std::string getREM();

         void outputREM(WINDOW *_winREM);


    private:
        std::string _REM;
};


#endif //FT_GKRELLM_REM_H
