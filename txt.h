#ifndef _TXT_H
#define _TXT_H



#pragma once
#include "engine.h"
#include <iostream>
#include <conio.h>

class txt:
		public engine
{
	public:
		void view(board &b)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					bool a = b.show_element(i * b.row + j);
					std::cout << a;
				}
				std::cout << std::endl;
			}

			_getch();
		}

		txt() :engine() {};
		txt(unsigned row, unsigned col) :engine(row, col) {};

		virtual ~txt() = 0;
};

#endif // !_TXT_H