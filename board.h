#ifndef _BOARD_H_
#define _BOARD_H

#pragma once

class board
{
	public:
		unsigned row, col;
		bool* tab;

	public: //konstruktory kopiuj¹ce + operatory przypisania, mog¹ byæ tylko zablokowane
			// = delete -> standard 11
		board() {
			row = 10;
			col = 10;

			tab = new bool[row * col];

			for (int i = 0; i < row * col; i++)
			{
				tab[i] = 0;
			}
		}

		board(unsigned x, unsigned y) {
			this->row = x;
			this->col = y;

			tab = new bool[row * col];

			for (int i = 0; i < row * col; i++)
			{
				tab[i] = 0; 
			}
		}

		~board() {
			delete[] tab;
		}

		bool show_element(int i)
		{
			return tab[i];
		}
protected:
		void cycle_of_life() //przechodzi przez wszystkie elementy tablicy
		{
			bool *copy = new bool[row * col];

			for (int i = 0; i < row * col; i++)
			{
				copy[i] = new bool[dead_or_alive(i)];
			}

			for (int i = 0; i < row * col; i++) tab[i] = copy[i];

			delete[] copy;
		}
private:
		bool dead_or_alive(int pos)
		{
			int alive = 0;

			if (tab[pos - 1 - row] ) alive++; //po lewy górny róg
			if (tab[pos - row] ) alive++; //nad aktualna pozycj¹
			if (tab[pos - row + 1] ) alive++; //prawy górny skos
			if (tab[pos - 1 ] ) alive++; //po lewo
			if (tab[pos + 1 ] ) alive++; // po prawo
			if (tab[pos + row] ) alive++; //na dole
			if (tab[pos + row - 1] ) alive++; //lewy dolny róg
			if (tab[pos + row + 1] ) alive++; //prawy dolny róg

			if (!tab[pos] && alive == 3 ) return true;
			if (tab[pos] && (alive == 2 || alive == 3)) return true;
				else return false;
		}

		
};

#endif // !_BOARD_H_