/*
    Klasa board sluzy do utworzenia plaszczyzny wraz z komorkami gry.
    Sprawdza zalezności miedzy komprkami.
    Autor: Eliza Mrowczynska


    Dodać konstruktory kopiujące i operatory przypisania
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

    virtual ~board();

    bool& operator[](int i) const;

    int get_size() const;

protected:
    void cycle_of_life();
    const board(const board& other) = delete;
    board& operator=(const board& other) = delete;

private:
    bool dead_or_alive(int pos);

   
};

#endif // !_BOARD_H