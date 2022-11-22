//
// Created by Bartek on 22.11.2022.
//

#include "Board.h"
Board::Board(int player_count) {
    clean();
    set_blue_base();
    set_green_base();
    set_red_base();
    set_yellow_base();
    set_plansze();
}

void Board::clean() {
    for (int iterator = 0; iterator < 11; ++iterator) {
        for (int j = 0; j < 11; ++j) {
            plansza[iterator][j].pole = empty;
            clear_pawn(iterator, j);
        }
    }

}

void Board::set_blue_base() {
    plansza[0][0].pole = base_blue;
    plansza[0][1].pole = base_blue;
    plansza[1][0].pole = base_blue;
    plansza[1][1].pole = base_blue;

    plansza[0][0].blue = 1;
    plansza[0][1].blue = 1;
    plansza[1][0].blue = 1;
    plansza[1][1].blue = 1;
}

void Board::set_green_base() {
    plansza[0][10].pole = base_green;
    plansza[0][9].pole = base_green;
    plansza[1][10].pole = base_green;
    plansza[1][9].pole = base_green;

    plansza[0][10].green = 1;
    plansza[0][9].green = 1;
    plansza[1][10].green = 1;
    plansza[1][9].green = 1;
}

void Board::set_yellow_base() {
    plansza[10][0].pole = base_yellow;
    plansza[9][0].pole = base_yellow;
    plansza[10][1].pole = base_yellow;
    plansza[9][1].pole = base_yellow;

    plansza[10][0].yellow = 1;
    plansza[9][0].yellow = 1;
    plansza[10][1].yellow = 1;
    plansza[9][1].yellow = 1;
}

void Board::set_red_base() {
    plansza[10][10].pole = base_red;
    plansza[9][10].pole = base_red;
    plansza[10][9].pole = base_red;
    plansza[9][9].pole = base_red;

    plansza[10][10].red = 1;
    plansza[9][10].red = 1;
    plansza[10][9].red = 1;
    plansza[9][9].red = 1;
}

void Board::displey() {

    for (int row = 0; row < 11; ++row) {
        std::cout<<"|";
        for (int col = 0; col < 11; ++col) {
            std::cout<<what_on_board(row, col)<<"|";
        }
        std::cout<<std::endl;
    }
}

char Board::what_on_board(int row, int col) {
    if(plansza[row][col].pole == base_red){
        return 'R';
    }
    if(plansza[row][col].pole == base_blue){
        return 'B';
    }
    if(plansza[row][col].pole == base_green){
        return 'G';
    }
    if(plansza[row][col].pole == base_yellow){
        return 'Y';
    }
    if(plansza[row][col].pole == pole){
        return 'P';
    }
    if(plansza[row][col].pole == win_blue){
        return 'b';
    }
    if(plansza[row][col].pole == win_green){
        return 'g';
    }
    if(plansza[row][col].pole == win_red){
        return 'r';
    }
    if(plansza[row][col].pole == win_yellow){
        return 'y';
    }
}

void Board::set_plansze() {
    for (int row = 4; row <= 6; ++row) {
        plansza[row][0].pole = pole;
        clear_pawn(row,0);

    }
    for (int col = 4; col <= 6; ++col) {
        plansza[0][col].pole = pole;
        clear_pawn(0,col);
    }
    for (int col = 4; col <= 6; ++col) {
        plansza[10][col].pole = pole;
        clear_pawn(10,col);
    }
    for (int row = 4; row <= 6; ++row) {
        plansza[row][10].pole = pole;
        clear_pawn(row,10);
    }

    // ................................

    for (int row = 0; row <= 4; ++row) {
        plansza[row][6].pole = pole;
        clear_pawn(row,6);
    }
    for (int row = 0; row <= 4; ++row) {
        plansza[row][4].pole = pole;
        clear_pawn(row,4);
    }

    for (int col = 0; col <= 4; ++col) {
        plansza[4][col].pole = pole;
        clear_pawn(4,col);
    }
    for (int col = 0; col <= 4; ++col) {
        plansza[6][col].pole = pole;
        clear_pawn(6,col);
    }
    //...................................

    for (int row = 10; row >= 6; --row) {
        plansza[row][6].pole = pole;
        clear_pawn(row,6);
    }
    for (int row = 10; row >= 6; --row) {
        plansza[row][4].pole = pole;
        clear_pawn(row,4);
    }

    for (int col = 10; col >= 6; --col) {
        plansza[4][col].pole = pole;
        clear_pawn(4,col);

    }
    for (int col = 10; col >= 6; --col) {
        plansza[6][col].pole = pole;
        clear_pawn(6,col);
    }
    // ...................................

    for (int col = 1; col <= 4; ++col) {
        plansza[5][col].pole = win_blue;
        clear_pawn(5,col);
    }
    for (int row = 1; row <= 4; ++row) {
        plansza[row][5].pole = win_green;
        clear_pawn(row,5);
    }
    for (int col = 9; col >= 6; --col) {
        plansza[5][col].pole = win_red;
        clear_pawn(5,col);
    }
    for (int row = 9; row >= 6; --row) {
        plansza[row][5].pole = win_yellow;
        clear_pawn(row,5);
    }
}

void Board::clear_pawn(int row, int col) {
    plansza[row][col].red = 0;
    plansza[row][col].green = 0;
    plansza[row][col].blue = 0;
    plansza[row][col].yellow = 0;
}
