
#ifndef _ENGINE_H
#define _ENGINE_H


#pragma once

#include "board.h"
#include <cstdlib>
#include <conio.h>

class engine : public board // why ???
{

public:
    engine() = delete;

    engine(unsigned row, unsigned col) : board(row, col) {};

    virtual void view() = 0;

    // get it? ??????????????
    [[noreturn]] void play() {
        while (2 > 1) {
            view();
            getch();
            cycle_of_life();
            system("cls");
        }
    }


};

#endif //!_BOARD_H