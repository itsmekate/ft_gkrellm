//
// Created by Kateryna PRASOL on 14.10.2018.
//

#include "Cat.h"

Cat::Cat() {}

Cat::~Cat() {

}

Cat::Cat(Cat const &rhs)
{
    *this = rhs;
}
Cat const & Cat::operator=(Cat const &rhs)
{
    (void)rhs;
    return (*this);

}

void Cat::print_cat1(WINDOW *_winCAT)
{
    wattron(_winCAT, A_BOLD);
    wattron(_winCAT, COLOR_PAIR(6));
    mvwprintw(_winCAT, 1, 2, "                 ,.     ,.");
    mvwprintw(_winCAT, 2, 2, "                {^ \\-\"-/ ^}");
    mvwprintw(_winCAT, 3, 2, "                \"   \"\"\"   \"");
    mvwprintw(_winCAT, 4, 2, "               { <O> _ <O> }");
    mvwprintw(_winCAT, 5, 2, "               ==_ .:Y:. _==");
    mvwprintw(_winCAT, 6, 2, "             .\"\"  `--^--' \"\".");
    mvwprintw(_winCAT, 7, 2, "            (,~-~.\"\" \"\" ,~-~.)");
    mvwprintw(_winCAT, 8, 2, "      ------(     )----(     )-----");
    mvwprintw(_winCAT, 9, 2, "            ^-'-'-^    ^-'-'-^");
    mvwprintw(_winCAT, 10, 2,"      _____________________________");
    mvwprintw(_winCAT, 11, 2,"            |\"\"\"\" /~.^.~\\ \"\"\"\"|");
    mvwprintw(_winCAT, 12, 2,"      hjw    ,i-i-i(\"\"(  i-i-i.");
    mvwprintw(_winCAT, 13, 2,"      `97   (o o o ))\"\")( o o o)");
    mvwprintw(_winCAT, 14, 2,"             \\(_) /(\"\"(  \\ (_)/");
    mvwprintw(_winCAT, 15, 2,"              `--'  \\\"\"\\  `--'");
    mvwprintw(_winCAT, 16, 2,"                     )\"\")");
    mvwprintw(_winCAT, 17, 2,"                    (\"\"/");
    mvwprintw(_winCAT, 18, 2,"                     `\"");
    wattroff(_winCAT, COLOR_PAIR(6));
    wattroff(_winCAT, A_BOLD);
    wattron(_winCAT, COLOR_PAIR(1));
    box(_winCAT, 0, 0);
    wattroff(_winCAT, COLOR_PAIR(1));
    wrefresh(_winCAT);
}
void Cat::print_cat2(WINDOW *_winCAT)
{
    wattron(_winCAT, COLOR_PAIR(7));
    for (int i = 1; i < 18; ++i) {
        mvwprintw(_winCAT, i, 2,"            |\"\"\"\" /~.^.~\\ \"\"\"\"|");
    }
    wattroff(_winCAT, COLOR_PAIR(7));
    wattron(_winCAT, A_BOLD);
    wattron(_winCAT, COLOR_PAIR(6));
    mvwprintw(_winCAT, 1, 2, "                 ,.     ,.");
    mvwprintw(_winCAT, 2, 2, "                {^ \\-\"-/ ^}");
    mvwprintw(_winCAT, 3, 2, "                \"   \"\"\"   \"");
    mvwprintw(_winCAT, 4, 2, "               { <O> _ <O> }");
    mvwprintw(_winCAT, 5, 2, "               ==_ .:Y:. _==");
    mvwprintw(_winCAT, 6, 2, "             .\"\"  `--^--' \"\".");
    mvwprintw(_winCAT, 7, 2, "            (,~-~.\"\" \"\" ,~-~.)");
    mvwprintw(_winCAT, 8, 2, "      ------(     )----(     )-----");
    mvwprintw(_winCAT, 9, 2, "            ^-'-'-^    ^-'-'-^");
    mvwprintw(_winCAT, 10, 2,"      _____________________________");
    mvwprintw(_winCAT, 11, 2,"            |\"\"\"\" /~.^.~\\ \"\"\"\"|");
    mvwprintw(_winCAT, 12, 2,"      hjw    ,i-i-i)\"\")  i-i-i.");
    mvwprintw(_winCAT, 13, 2,"      `97   (o o o )(\"\"(( o o o)");
    mvwprintw(_winCAT, 14, 2,"             \\(_) / )\"\") \\ (_)/");
    mvwprintw(_winCAT, 15, 2,"              `--'  /\"\"/   `--'");
    mvwprintw(_winCAT, 16, 2,"                    (\"\"(");
    mvwprintw(_winCAT, 17, 2,"                    )\"\"\\");
    mvwprintw(_winCAT, 18, 2,"                    \"`");
    wattroff(_winCAT, COLOR_PAIR(6));
    wattroff(_winCAT, A_BOLD);
    wattron(_winCAT, COLOR_PAIR(1));
    box(_winCAT, 0, 0);
    wattroff(_winCAT, COLOR_PAIR(1));
    wrefresh(_winCAT);
}

void Cat::outputCPU(WINDOW *_winCPU){(void) _winCPU;}
void Cat::outputNetwork(WINDOW *_winNetwork){(void) _winNetwork;}
void Cat::outputREM(WINDOW *_winREM){(void) _winREM;}
void Cat::outputOSInfoWindow(WINDOW *_winOSInfo){(void) _winOSInfo;}