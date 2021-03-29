#ifndef _BOARD_H_
#define _BOARD_H

#pragma once

class board {
protected:
    unsigned row, col;
    bool *tab;

public:
    board() {
        row = 10;
        col = 10;
        tab = new bool[row * col];
        for (int i = 0; i < row * col; i++) tab[i] = false;
    }

    board(unsigned x, unsigned y) {
        row = x;
        col = y;
        tab = new bool[row * col];
        for (int i = 0; i < row * col; i++) tab[i] = false;

    }

    ~board() {
        delete[] tab;
    }

    bool &operator[](int i) const {
        return tab[i];
    }

    int get_size() const { return row * col; }

protected:
    void cycle_of_life() //przechodzi przez wszystkie elementy tablicy
    {
        bool *copy = new bool[row * col];

        for (int i = 0; i < row * col; i++) copy[i] = dead_or_alive(i);

        for (int i = 0; i < row * col; i++) tab[i] = copy[i];

        delete[] copy;
    }

private:
    bool dead_or_alive(int pos) {
        // my attempt :
        /*
        int alive = 0;

        if (tab[pos - 1 - row] ) alive++; //po lewy g�rny r�g
        if (tab[pos - row] ) alive++; //nad aktualna pozycj�
        if (tab[pos - row + 1] ) alive++; //prawy g�rny skos
        if (tab[pos - 1 ] ) alive++; //po lewo
        if (tab[pos + 1 ] ) alive++; // po prawo
        if (tab[pos + row] ) alive++; //na dole
        if (tab[pos + row - 1] ) alive++; //lewy dolny r�g
        if (tab[pos + row + 1] ) alive++; //prawy dolny r�g

        if (!tab[pos] && alive == 3 ) return true;
        if (tab[pos] && (alive == 2 || alive == 3)) return true;
            else return false;
         */
        // provided by @piotr233
        // implementing infinite space:
        /*
        unsigned live_count = 0;

        unsigned ix = pos / col;
        unsigned iy = pos % row;

        std::pair<int, int> surrounding[8];

        surrounding[0] = {ix - 1, iy - 1};
        surrounding[1] = {ix - 1, iy};
        surrounding[2] = {ix - 1, iy + 1};
        surrounding[3] = {ix, iy - 1};
        surrounding[4] = {ix, iy + 1};
        surrounding[5] = {ix + 1, iy - 1};
        surrounding[6] = {ix + 1, iy};
        surrounding[7] = {ix + 1, iy + 1};

        if (ix == 0) {
            surrounding[0].first = col - 1;
            surrounding[1].first = col - 1;
            surrounding[2].first = col - 1;
        } else if (ix == col - 1) {
            surrounding[5].first = 0;
            surrounding[6].first = 0;
            surrounding[7].first = 0;
        }


        if (iy == 0) {
            surrounding[0].second = row - 1;
            surrounding[3].second = row - 1;
            surrounding[5].second = row - 1;
        } else if (iy == row - 1) {
            surrounding[2].second = 0;
            surrounding[4].second = 0;
            surrounding[7].second = 0;
        }

        */
        // implemented as "dead bounderies"
        unsigned live_count = 0;

        unsigned ix = pos / col;
        unsigned iy = pos % row;

        bool surrounding[8]; // cut from the "tab"

        //
        //    0 1 2
        //    3 x 4      // x == pos
        //    5 6 7
        //

        if (ix == 0) {
            surrounding[0] = false;
            surrounding[1] = false;
            surrounding[2] = false;
        } else surrounding[1] = tab[pos - row];


        if (ix == col - 1) {
            surrounding[5] = false;
            surrounding[6] = false;
            surrounding[7] = false;
        } else surrounding[6] = tab[pos + row];



        if (iy == 0) {
            surrounding[0] = false;
            surrounding[3] = false;
            surrounding[5] = false;
        } else {
            if (ix != 0)        surrounding[0] = tab[pos - 1 - row];
                                surrounding[3] = tab[pos - 1];
            if (ix != col - 1)  surrounding[5] = tab[pos - 1 + row];
        }


        if (iy == row - 1) {
            surrounding[2] = false;
            surrounding[4] = false;
            surrounding[7] = false;
        } else {
            if (ix != 0)        surrounding[2] = tab[pos + 1 - row];
                                surrounding[4] = tab[pos + 1];
            if (ix != col - 1)  surrounding[7] = tab[pos + 1 + row];
        }

        for (auto &i : surrounding) if (i) ++live_count;

        if (live_count == 3) return true;
        if (tab[pos] && live_count == 2) return true;

        return false;

    }
};

#endif // !_BOARD_H_