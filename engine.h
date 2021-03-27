
#ifndef _ENGINE_H
#define _ENGINE_H



#pragma once
#include "board.h"
#include <stdlib.h>

class engine:
		public board
{

	public:
		engine() {
			;
		}

		engine(unsigned row, unsigned col) :board(row, col) {};
		
		virtual ~engine() = 0;

		void play(board &b)
		{
			//petla
			//analiza tablicy
			//view();
			//nie wolno tu zadnych cin cout i innych uzywac
			//mozemy w txt albo api

			while (2 > 1)
			{
				view(b);
				this->cycle_of_life();
				system("cls");
			}
		}
		
	
		virtual void view(board &b) = 0;

};

#endif //!_BOARD_H