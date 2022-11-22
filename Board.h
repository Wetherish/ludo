//
// Created by Michal (with small help of Bartek) on 22.11.2022.
//

#ifndef LUDO_BOARD_H
#define LUDO_BOARD_H


#include <iostream>
#include <vector>
#include <array>
enum type_pole{base_green, base_red, base_blue, base_yellow, win_green, win_red, win_blue, win_yellow,
    start_green, start_red, start_blue, start_yellow, empty, pole};
struct square {
    int green = 0;
    int blue = 0;
    int red = 0;
    int yellow = 0;
    type_pole pole;


};


class Board{
public:

    Board(int player_count);
    void set_pole();
    void displey();
    // ~Board();
private:

    void clean();
    void set_blue_base();
    void set_green_base();
    void set_yellow_base();
    void set_red_base();
    void set_plansze();
    void clear_pawn(int row, int col);

    char what_on_board(int row, int col);

    // std::array<kwadracik>board[10];
    std::array<std::array<square,11>,11> board;


};

#endif //LUDO_BOARD_H
