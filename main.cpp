#include <iostream>
#include "string"
#include "board.h"


int main() {
    Board a (2) ;
    std::cout << a.counter_blue_base << std::endl;
    a.display();
    std::cout<<"bartek"<<std::endl;
    std::cout << "mike" << std::endl;
    a.spawn(blue, 6);
    a.display();
    std::cout << std::endl;
    a.spawn(red, 1);
    a.display();
    std::cout<<std::endl;
    a.spawn(yellow, 5);
    a.display();
    return 0;
}
