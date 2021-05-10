#include "board.h"

board::board()
{
    row = 10;
    col = 10;
    tab = new bool[row * col];
    for (int i = 0; i < row * col; i++) tab[i] = false;
}

board::board(unsigned x, unsigned y)
{
    row = x;
    col = y;
    tab = new bool[row * col];
    for (int i = 0; i < row * col; i++) tab[i] = false;

}

board::~board()
{
    if(tab) delete[] tab;
}

bool& board::operator[](int i) const
{
    return tab[i];
}

int board::get_size() const
{
    return row * col;
}

void board::cycle_of_life()
{
    bool* copy = new bool[row * col];

    for (int i = 0; i < row * col; i++) copy[i] = dead_or_alive(i);

    for (int i = 0; i < row * col; i++) tab[i] = copy[i];

    delete[] copy;
}

bool board::dead_or_alive(int pos)
{
    unsigned live_count = 0;

    unsigned in_row = pos / col;
    unsigned in_col = pos % row;

    bool neighbor[8]; // cut from the "tab"


    if (in_row == 0) {
        neighbor[0] = false;
        neighbor[1] = false;
        neighbor[2] = false;
    }
         else neighbor[1] = tab[pos - row];


    if (in_row == col - 1) {
        neighbor[5] = false;
        neighbor[6] = false;
        neighbor[7] = false;
    }
        else neighbor[6] = tab[pos + row];



    if (in_col == 0) {
        neighbor[0] = false;
        neighbor[3] = false;
        neighbor[5] = false;
    }
        else {
            if (in_row != 0)   neighbor[0] = tab[pos - 1 - row];
            neighbor[3] = tab[pos - 1];
            if (in_row != col - 1)  neighbor[5] = tab[pos - 1 + row];
        }


    if (in_col == row - 1) {
        neighbor[2] = false;
        neighbor[4] = false;
        neighbor[7] = false;
    }
        else {
            if (in_row != 0)  neighbor[2] = tab[pos + 1 - row];
            neighbor[4] = tab[pos + 1];
            if (in_row != col - 1)  neighbor[7] = tab[pos + 1 + row];
        }

    for (auto& i : neighbor) if (i) ++live_count;

    if (live_count == 3) return true;
    if (tab[pos] && live_count == 2) return true;

    return false;
}