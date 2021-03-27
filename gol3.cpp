#include <iostream>
#include "txt.h"

int main()
{
	board b(4, 4);

	for (int i = 0; i < 16; i++)
	{
		if (i == 2) b.tab[i] = 1;
		else b.tab[i] = 0;
	}

	engine *e = new txt();

	e->play(b);

	return 0;
}

