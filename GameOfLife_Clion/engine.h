/*
    Klasa engine jest klasa

    Autor: Eliza Mrówczyñska

*/

#ifndef _ENGINE_H
#define _ENGINE_H


#pragma once

#include "board.h"
#include <windows.h>

class engine : public board
{

public:
    engine() = delete;

    engine(unsigned row, unsigned col) : board(row, col) {};

    virtual void view() = 0;

    virtual void play() = 0;
  

    virtual ~engine() {};

private:
    const engine(const engine& other) = delete;
    engine& operator=(const engine& other) = delete;
   

};

#endif //!_BOARD_H