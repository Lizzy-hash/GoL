#ifndef _TXT_H
#define _TXT_H


#pragma once

#include "engine.h"
#include <iostream>


class txt : public engine {
public:
    txt(unsigned row, unsigned col) : engine(row, col) {};
    

    void view();

    bool decode_input(char input, int& current_position);
    void gen_ui_frame(int position);

    void ui();

    void play();
    virtual ~txt(){};

private:
    const txt(const txt& other) = delete;
    txt& operator=(const txt& other) = delete;
   
};

#endif // !_TXT_H