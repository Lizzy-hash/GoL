#include "txt.h"

void txt::view()
{
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            /*if (tab[i * row + j]) printf("# ");
            else printf("_ ");*/
            if (tab[i  + j]) printf("# ");
            else printf("_ ");
        }
        std::cout << std::endl;
    }
}

bool txt::decode_input(char input, int& current_position)
    {
        switch (input) {
        case 'a':
            current_position -= 1;
            if (current_position % row == row - 1) current_position += row;
            break;
        case 'w':
            current_position -= row;
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
            return true;

        case '1':
            if (current_position - 1 % row != row - 1) tab[current_position - 1] = true;
            tab[current_position] = true;
            if (current_position + 1 % row != 0) tab[current_position + 1] = true;

            break;
        case '2':
            if (current_position % row != row) tab[current_position] = true;
            if (current_position + 1 % row != row && current_position + 1 % col != col) tab[current_position + 1 + row] = true;
            if (current_position + 1 % row != row && current_position + 1 % col != col) tab[current_position + 1 + 2 * row] = true;
            if (current_position + 1 % row != row && current_position + 1 % col != col) tab[current_position + 2 * row] = true;
            if (current_position + 1 % row != row && current_position + 1 % col != col) tab[current_position - 1 + 2 * row] = true;
            break;
        default:
            return false;

        }
        return false;

    }

void txt::gen_ui_frame(int position)
{

    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < col; j++) {
            /*if (i * row + j == position) {
                if (tab[i * row + j]) printf("#<");
                else printf("_<");
            }
            else {
                if (tab[i * row + j]) printf("# ");
                else printf("_ ");
            }*/
            if (i + j == position) {
                if (tab[i  + j]) printf("#<");
                else printf("_<");
            }
            else {
                if (tab[i  + j]) printf("# ");
                else printf("_ ");
            }
        }
        std::cout << std::endl;
    }

}

void txt::ui()
{
    char player_input;

    int player_position = get_size() / 2;

    while (2 > 1) {

        gen_ui_frame(player_position);
        player_input = _getch();
        if (decode_input(player_input, player_position)) break;
        system("cls");
    }
}

void txt::play()
{
    ui();

    while (2 > 1) {
        system("cls");
        view();
        Sleep(500);
        cycle_of_life();

    }
}
