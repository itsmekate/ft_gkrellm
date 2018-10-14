#include "main.h"

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        std::string arg1(argv[1]);
        if(arg1 == "ncurses") {
            Ncurses *n = new Ncurses();
            n->runNcurses();
            delete n;
            return (0);
        }
//        else if(arg1 == "sdl") {
//            Ncurses *n = new Ncurses();
//            n->runNcurses();
//            delete n;
//            return (0);
//        }
        else
            std::cout << "Usage: ./ft_gkrellm || ncurses" << std::endl;
    }
    else
        std::cout << "Usage: ./ft_gkrellm || ncurses" << std::endl;
    return 0;
}