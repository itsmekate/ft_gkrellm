//
// Created by Kateryna PRASOL on 13.10.2018.
//

#ifndef FT_GKRELLM_NCURSES_H
#define FT_GKRELLM_NCURSES_H
#include <ncurses.h>
#include <unistd.h>

class Ncurses {
    public:
        Ncurses();
        Ncurses(Ncurses &rhs);
        Ncurses const & operator=(Ncurses & rhs);
        ~Ncurses();
        WINDOW *getWindow();
//        void draw_borders(WINDOW *screen);

    private:
        WINDOW *_win;
};


#endif //FT_GKRELLM_NCURSES_H
