/*
    Klasa engine jest klasa

    Autor: Eliza Mrówczyñska

*/

#ifndef _ENGINE_H
#define _ENGINE_H


#pragma once

#include "board.h"
#include <cstdlib>
#include <conio.h>

class engine : public board
{

public:
    engine() = delete;

    engine(unsigned row, unsigned col) : board(row, col) {};

    virtual void view() = 0;

    virtual void play() = 0;


};

#endif //!_BOARD_H