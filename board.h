/*
    Klasa board sluzy do utworzenia plaszczyzny wraz z komorkami gry.
    Sprawdza zalezności miedzy komprkami.

    Autor: Eliza Mrowczynska

*/

#ifndef _BOARD_H_
#define _BOARD_H

#pragma once

class board {
protected:
    unsigned row, col;  // ## col = 2
    bool* tab;          // ## row = 3
                        // ##
public:
    board();

    board(unsigned x, unsigned y);

    ~board();

    bool& operator[](int i) const;

    int get_size() const;

protected:
    void cycle_of_life();
  

private:
    bool dead_or_alive(int pos);
};

#endif // !_BOARD_H