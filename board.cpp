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
    delete[] tab;
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

    unsigned in_cols = pos / col;
    unsigned in_rows = pos % row;

    bool neighbors[8];


    if (in_cols == 0) {
        neighbors[0] = false;
        neighbors[1] = false;
        neighbors[2] = false;
    }
    else neighbors[1] = tab[pos - row];


    if (in_cols == col - 1) {
        neighbors[5] = false;
        neighbors[6] = false;
        neighbors[7] = false;
    }
    else neighbors[6] = tab[pos + row];



    if (in_rows == 0) {
        neighbors[0] = false;
        neighbors[3] = false;
        neighbors[5] = false;
    }
    else {
        if (in_cols != 0)  neighbors[0] = tab[pos - 1 - row];
        neighbors[3] = tab[pos - 1];
        if (in_cols != col - 1) neighbors[5] = tab[pos - 1 + row];
    }


    if (in_rows == row - 1) {
        neighbors[2] = false;
        neighbors[4] = false;
        neighbors[7] = false;
    }
    else {
        if (in_cols != 0) neighbors[2] = tab[pos + 1 - row];
        neighbors[4] = tab[pos + 1];
        if (in_cols != col - 1) neighbors[7] = tab[pos + 1 + row];
    }

    for (auto& i : neighbors) if (i) ++live_count;

    if (live_count == 3) return true;
    if (tab[pos] && live_count == 2) return true;

    return false;
}
