#include <iostream>

#include "sudoku.hpp"

int main() {
    Sudoku s;
    s.set_square(0, 0, 1);
    s.set_square(0, 1, 2);
    s.set_square(0, 2, 3);
    s.set_square(1, 0, 4);
    s.set_square(1, 1, 5);
    s.set_square(1, 2, 6);
    s.set_square(2, 0, 7);
    s.set_square(2, 1, 8);
    s.set_square(2, 2, 9);
    s.print();
    return 0;
}
