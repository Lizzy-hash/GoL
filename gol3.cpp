#include <iostream>
#include "txt.h"


int main()
{
    txt b(5, 5);
    b[11] = true;
    b[12] = true;
    b[13] = true;

    b.play();

	return 0;
}

