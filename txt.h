#ifndef _TXT_H
#define _TXT_H


#pragma once

#include "engine.h"
#include <iostream>
#include <conio.h>

class txt :
        public engine {
public:
    txt(unsigned row, unsigned col) : engine(row, col) {};

    void view() {
        for (unsigned i = 0; i < row; i++) {
            for (unsigned j = 0; j < col; j++) {
                if (tab[i * row + j]) printf("# ");
                else printf("_ ");
            }
            std::cout << std::endl;
        }
    }


};

#endif // !_TXT_H