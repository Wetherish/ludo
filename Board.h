//
// Created by Michal (with small help of Bartek) on 22.11.2022.
//

#ifndef LUDO_BOARD_H
#define LUDO_BOARD_H


#include <iostream>
#include <vector>
#include <array>
enum type_space{base_green, base_red, base_blue, base_yellow, win_green, win_red, win_blue, win_yellow,
    start_green, start_red, start_blue, start_yellow, empty, space};
enum pawn_colour {green, red, blue, yellow};
struct square {
    int green = 0;
    int blue = 0;
    int red = 0;
    int yellow = 0;
    type_space space;

};
struct pawn{
    pawn_colour type;
    int row;
    int col;

};

class Board{
public:

    explicit Board(int player_count);
    void set_space();
    void display();
    void move();
    void spawn(pawn_colour colour, int roll);
    int counter_blue_base = 4;
    int counter_red_base = 4;
    int counter_green_base = 4;
    int counter_yellow_base = 4;
    
    // ~Board();
private:
    pawn b1,b2,b3,b4;
    pawn g1,g2,g3,g4;
    pawn y1,y2,y3,y4;
    pawn r1,r2,r3,r4;

    

    void clean();
    void set_blue_base();
    void set_green_base();
    void set_yellow_base();
    void set_red_base();
    void set_board();
    void clear_pawn(int row, int col);

    char what_on_board(int row, int col);
    

    // std::array<kwadracik>board[10];
    std::array<std::array<square,11>,11> board;


};

#endif //LUDO_BOARD_H
