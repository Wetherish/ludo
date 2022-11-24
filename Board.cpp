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
    set_board();

    b1.type = blue;
    b2.type = blue;
    b3.type = blue;
    b4.type = blue;

    g1.type = green;
    g2.type = green;
    g3.type = green;
    g4.type = green;

    r1.type = red;
    r2.type = red;
    r3.type = red;
    r4.type = red;

    y1.type = yellow;
    y2.type = yellow;
    y3.type = yellow;
    y4.type = yellow;
}

void Board::clean() {
    for (int iterator = 0; iterator < 11; ++iterator) {
        for (int j = 0; j < 11; ++j) {
            board[iterator][j].space = empty;
            clear_pawn(iterator, j);
        }
    }

}

void Board::set_blue_base() {
    board[0][0].space = base_blue;
    board[0][1].space = base_blue;
    board[1][0].space = base_blue;
    board[1][1].space = base_blue;

    board[0][0].blue = 1;
    board[0][1].blue = 1;
    board[1][0].blue = 1;
    board[1][1].blue = 1;

    b1.row = 0; b1.col = 0;
    b2.row = 0; b2.col = 1;
    b3.row = 1; b3.col = 0;
    b4.row = 1; b4.col = 1;
}

void Board::set_green_base() {
    board[0][10].space = base_green;
    board[0][9].space = base_green;
    board[1][10].space = base_green;
    board[1][9].space = base_green;

    board[0][10].green = 1;
    board[0][9].green = 1;
    board[1][10].green = 1;
    board[1][9].green = 1;

    g1.row = 0 ; g1.col = 10;
    g2.row = 0 ; g2.col = 9;
    g3.row = 1 ; g3.col = 10;
    g4.row = 1 ; g4.col = 9;
}

void Board::set_yellow_base() {
    board[10][0].space = base_yellow;
    board[9][0].space = base_yellow;
    board[10][1].space = base_yellow;
    board[9][1].space = base_yellow;

    board[10][0].yellow = 1;
    board[9][0].yellow = 1;
    board[10][1].yellow = 1;
    board[9][1].yellow = 1;

    y1.row = 10; y1.col = 0;
    y2.row = 9; y2.col = 0;
    y3.row = 10; y3.col = 1;
    y4.row = 9; y4.col = 1;
}

void Board::set_red_base() {
    board[10][10].space = base_red;
    board[9][10].space = base_red;
    board[10][9].space = base_red;
    board[9][9].space = base_red;

    board[10][10].red = 1;
    board[9][10].red = 1;
    board[10][9].red = 1;
    board[9][9].red = 1;

    r1.row = 10; r1.col = 10;
    r2.row = 9; r2.col = 10;
    r3.row = 10; r3.col = 9;
    r4.row = 9; r4.col = 9;
}

void Board::display() {

    for (int row = 0; row < 11; ++row) {
        std::cout<<"|";
        for (int col = 0; col < 11; ++col) {
            std::cout<<what_on_board(row, col)<<"|";
        }
        std::cout<<std::endl;
    }
}

char Board::what_on_board(int row, int col) {
    if(board[row][col].space == empty){
        return ' ';
    }

    if(board[row][col].space == base_red){
        return 'R';
    }
    if(board[row][col].space == base_blue){
        return 'B';
    }
    if(board[row][col].space == base_green){
        return 'G';
    }
    if(board[row][col].space == base_yellow){
        return 'Y';
    }
    if(board[row][col].space == space){
        return 'P';
    }
    if(board[row][col].space == win_blue){
        return 'b';
    }
    if(board[row][col].space == win_green){
        return 'g';
    }
    if(board[row][col].space == win_red){
        return 'r';
    }
    if(board[row][col].space == win_yellow){
        return 'y';
    }
}

void Board::set_board() {
    for (int row = 4; row <= 6; ++row) {
        board[row][0].space = space;
        clear_pawn(row,0);

    }
    for (int col = 4; col <= 6; ++col) {
        board[0][col].space = space;
        clear_pawn(0,col);
    }
    for (int col = 4; col <= 6; ++col) {
        board[10][col].space = space;
        clear_pawn(10,col);
    }
    for (int row = 4; row <= 6; ++row) {
        board[row][10].space = space;
        clear_pawn(row,10);
    }

    // ................................

    for (int row = 0; row <= 4; ++row) {
        board[row][6].space = space;
        clear_pawn(row,6);
    }
    for (int row = 0; row <= 4; ++row) {
        board[row][4].space = space;
        clear_pawn(row,4);
    }

    for (int col = 0; col <= 4; ++col) {
        board[4][col].space = space;
        clear_pawn(4,col);
    }
    for (int col = 0; col <= 4; ++col) {
        board[6][col].space = space;
        clear_pawn(6,col);
    }
    //...................................

    for (int row = 10; row >= 6; --row) {
        board[row][6].space = space;
        clear_pawn(row,6);
    }
    for (int row = 10; row >= 6; --row) {
        board[row][4].space = space;
        clear_pawn(row,4);
    }

    for (int col = 10; col >= 6; --col) {
        board[4][col].space = space;
        clear_pawn(4,col);

    }
    for (int col = 10; col >= 6; --col) {
        board[6][col].space = space;
        clear_pawn(6,col);
    }
    // ...................................

    for (int col = 1; col <= 4; ++col) {
        board[5][col].space = win_blue;
        clear_pawn(5,col);
    }
    for (int row = 1; row <= 4; ++row) {
        board[row][5].space = win_green;
        clear_pawn(row,5);
    }
    for (int col = 9; col >= 6; --col) {
        board[5][col].space = win_red;
        clear_pawn(5,col);
    }
    for (int row = 9; row >= 6; --row) {
        board[row][5].space = win_yellow;
        clear_pawn(row,5);
    }
}

void Board::clear_pawn(int row, int col) {
    board[row][col].red = 0;
    board[row][col].green = 0;
    board[row][col].blue = 0;
    board[row][col].yellow = 0;
}

void Board::move() {


}

void Board::set_space() {

}

void Board::spawn() {


}
