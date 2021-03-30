#ifndef _TXT_H
#define _TXT_H


#pragma once

#include "engine.h"
#include <iostream>
#include <conio.h>


class txt : public engine {
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

    bool decode_input(char input, int &current_position) {
        switch (input) {
            case 'a':
                current_position -= 1;
                if (current_position % row == row - 1) current_position += row;
                break;
            case 'w':
                current_position -= row; // idk które jest które
                if (current_position < 0)
                    current_position = get_size() + current_position;

                break;
            case 's':
                current_position += row;
                if (current_position >= get_size())
                    current_position = current_position - get_size();

                break;
            case 'd':
                current_position += 1;
                if (current_position % row == 0) current_position -= row;
                break;
            case 'e':
                tab[current_position] = !tab[current_position];
                break;
            case ' ':
                return true; // exit ui

            case '1':
                if (current_position - 1 % row != row - 1) tab[current_position - 1] = true;
                tab[current_position] = true;
                if (current_position + 1 % row != 0) tab[current_position + 1] = true;

                break;
            case '2':
                break;
            case '3':
                break;
            default:
                return false;

        }
        return false;

    }

    void gen_ui_frame(int position) {

        for (unsigned i = 0; i < row; i++) {
            for (unsigned j = 0; j < col; j++) {
                if (i * row + j == position) {
                    if (tab[i * row + j]) printf("#<");
                    else printf("_<");
                } else {
                    if (tab[i * row + j]) printf("# ");
                    else printf("_ ");
                }
            }
            std::cout << std::endl;
        }

    }

    void ui() {
        char player_input;
        // can be a w s d for controls
        // space for starting the game
        // e changes controlled square from dead to alive
        //     and vice versa
        // 0 to 9 for some pre made shapes


        int player_position = get_size() / 2;
        std::cout << "a w s d for controls\n"
                     "space start's simulation\n"
                     "e changes controlled square from dead to alive\n"
                     "  and vice versa\n"
                     "0-9 puts mos known shapes\n";

        while (2 > 1) {

            gen_ui_frame(player_position);
            player_input = getch();
            if (decode_input(player_input, player_position)) break;
            system("cls");

        }
    }

// get it? ??????????????
    [[noreturn]] void play() {
        ui();

        while (2 > 1) {
            system("cls");
            view();
            getch();
            cycle_of_life();

        }
    }


};

#endif // !_TXT_H