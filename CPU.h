//
// Created by Kateryna PRASOL on 13.10.2018.
//

#ifndef FT_GKRELLM_CPU_H
#define FT_GKRELLM_CPU_H
#include <string>

class CPU {
    public:
        CPU();
        CPU(CPU const &rhs);
        CPU const & operator=(CPU const &rhs);
        ~CPU();
        std::string getCPU();


    private:
        std::string _CPU;
};


#endif //FT_GKRELLM_CPU_H
