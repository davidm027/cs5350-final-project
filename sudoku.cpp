#include "sudoku.hpp"

#include <cassert>
#include <iostream>

Sudoku::Sudoku() {
    this->grid = this->initialize_grid();
}

std::array<std::array<int, 9>, 9> Sudoku::initialize_grid() {
    std::array<std::array<int, 9>, 9> final_grid{};
    grid.fill({0, 0, 0, 0, 0, 0, 0, 0, 0});
    return grid;
}

int Sudoku::get_square(int row, int col) {
    assert(row >= 0 && row <= 8 && "Desired row must be in between 0 and 8.");
    assert(col >= 0 && col <= 8 && "Desired column must be in between 0 and 8.");
    return this->grid.at(row).at(col);
}

void Sudoku::set_square(int row, int col, int value) {
    assert(row >= 0 && row <= 8 && "Desired row must be in between 0 and 8.");
    assert(col >= 0 && col <= 8 && "Desired column must be in between 0 and 8.");
    assert(value >= 1 && value <= 9 && "Desired value must be in between 1 and 9.");
    this->grid.at(row).at(col) = value;
}

std::array<std::array<int, 9>, 9> Sudoku::get_grid() {
    return this->grid;
}

void Sudoku::print() {
    std::cout << "╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n";
    for (int i = 0; i < 9; ++i) {
        std::cout << "║";
        for (int j = 0; j < 9; ++j) {
            int item = this->get_square(i, j);
            std::cout << " " << item << " ";
            if ((j + 1) % 3 == 0) {
                std::cout << "║";
            } else {
                std::cout << "│";
            }
        }
        std::cout << "\n";
        if ((i + 1) != 9) {
            if ((i + 1) % 3 == 0) {
                std::cout << "╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣";
            } else {
                std::cout << "╟───┼───┼───╫───┼───┼───╫───┼───┼───╢";
            }
            std::cout << "\n";
        }
    }
    std::cout << "╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝\n";
}