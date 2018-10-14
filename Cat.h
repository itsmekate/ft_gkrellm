//
// Created by Kateryna PRASOL on 14.10.2018.
//

#ifndef FT_GKRELLM_CAT_H
#define FT_GKRELLM_CAT_H
#include "IMonitorModule.h"

class Cat : public IMonitorModule {
    public:
        Cat();
        Cat(Cat const &rhs);
        Cat const & operator=(Cat const &rhs);
        virtual ~Cat();

        void print_cat1(WINDOW *_winCAT);
        void print_cat2(WINDOW *_winCAT);
        void outputCPU(WINDOW *_winCPU);
        void outputNetwork(WINDOW *_winNetwork);
        void outputREM(WINDOW *_winREM);
        void outputOSInfoWindow(WINDOW *_winOSInfo);

};


#endif //FT_GKRELLM_CAT_H
