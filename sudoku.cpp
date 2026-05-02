#include "sudoku.hpp"

#include <cassert>
#include <iostream>
#include <set>

Sudoku::Sudoku()
{
    this->grid = this->initialize_grid();
}

std::array<std::array<int, 9>, 9> Sudoku::initialize_grid()
{
    std::array<std::array<int, 9>, 9> final_grid{};
    final_grid.fill({0, 0, 0, 0, 0, 0, 0, 0, 0});
    return final_grid;
}

int Sudoku::get_space(int row, int col)
{
    assert(row >= 0 && row <= 8 && "Desired row must be in between 0 and 8.");
    assert(col >= 0 && col <= 8 && "Desired column must be in between 0 and 8.");
    return this->grid.at(row).at(col);
}

void Sudoku::set_space(int row, int col, int value)
{
    assert(row >= 0 && row <= 8 && "Desired row must be in between 0 and 8.");
    assert(col >= 0 && col <= 8 && "Desired column must be in between 0 and 8.");
    assert(value >= 1 && value <= 9 && "Desired value must be in between 1 and 9.");
    this->grid.at(row).at(col) = value;
}

std::array<std::array<int, 9>, 9> Sudoku::get_grid()
{
    return this->grid;
}

std::array<int, 9> Sudoku::get_row(int row_index)
{
    assert(row_index >= 0 && row_index <= 8 && "Desired row must be in between 0 and 8.");

    std::array<int, 9> row;
    for (int col = 0; col < 9; col++)
    {
        row[col] = this->get_space(row_index, col);
    }

    return row;
}

std::array<int, 9> Sudoku::get_column(int column_index)
{
    assert(column_index >= 0 && column_index <= 8 && "Desired column must be in between 0 and 8.");

    std::array<int, 9> column;
    for (int row = 0; row < 9; row++)
    {
        column[row] = this->get_space(row, column_index);
    }

    return column;
}

std::array<int, 9> Sudoku::get_square(int square_index)
{
    assert(square_index >= 0 && square_index <= 8 && "Desired square must be in between 0 and 8.");
    int row;
    int col;

    std::array<int, 9> square;
    switch (square_index)
    {
        case 0:
            col = 1;
            row = 1;
            break;
        case 1:
            col = 4;
            row = 1;
            break;
        case 2:
            col = 7;
            row = 1;
            break;
        case 3:
            col = 1;
            row = 4;
            break;
        case 4:
            col = 4;
            row = 4;
            break;
        case 5:
            col = 7;
            row = 4;
            break;
        case 6:
            col = 1;
            row = 7;
            break;
        case 7:
            col = 4;
            row = 7;
            break;
        case 8:
            col = 7;
            row = 7;
            break;
        default:
            col = 0;
            row = 0;
            break;
    }

    int idx = 0;
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            square[idx++] = this->get_space(i, j);
        }
    }

    return square;
}

void Sudoku::set_square(int square_index, std::vector<int> values)
{
    assert(square_index >= 0 && square_index <= 8 && "Desired square must be in between 0 and 8.");
    int row;
    int col;

    switch (square_index)
    {
        case 0:
            col = 1;
            row = 1;
            break;
        case 1:
            col = 4;
            row = 1;
            break;
        case 2:
            col = 7;
            row = 1;
            break;
        case 3:
            col = 1;
            row = 4;
            break;
        case 4:
            col = 4;
            row = 4;
            break;
        case 5:
            col = 7;
            row = 4;
            break;
        case 6:
            col = 1;
            row = 7;
            break;
        case 7:
            col = 4;
            row = 7;
            break;
        case 8:
            col = 7;
            row = 7;
            break;
        default:
            col = 0;
            row = 0;
            break;
    }

    int idx = 0;
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            auto value = values[idx++];
            this->set_space(i, j, value);
        }
    }
}

void Sudoku::set_grid(std::vector<std::vector<int>> values)
{
    assert(values.size() == 9);
    for (int i = 0; i < 9; i++)
    {
        this->set_square(i, values[i]);
    }
}


bool Sudoku::contains(const std::array<int, 9>& arr, int val) {
    for (int row = 0; row < 9; row++) {
        if (arr[row] == val) return true;
    }
    return false;
}

int Sudoku::find_square(int row, int column) {
    int r = row / 3 ;
    int c = column / 3 ;
    return r * 3 + c;
}

bool Sudoku::is_choice_valid(int row, int col, int value){

    if (contains(get_column(col), value) or contains(get_row(row), value) or contains(get_square(find_square(row, col)), value)) {
        return false;
    }
    return true;
}

bool Sudoku::is_valid()
{
    for (int i = 0; i < 9; i++)
    {
        auto          row = this->get_row(i);
        std::set<int> row_set(row.begin(), row.end());
        auto          col = this->get_column(i);
        std::set<int> col_set(col.begin(), col.end());
        auto          square = this->get_square(i);
        std::set<int> square_set(square.begin(), square.end());
        if (row_set.size() != 9 || col_set.size() != 9 || square_set.size() != 9)
        {
            return false;
        }
    }
    return true;
}

void Sudoku::print()
{
    std::cout << "╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n";
    for (int i = 0; i < 9; ++i)
    {
        std::cout << "║";
        for (int j = 0; j < 9; ++j)
        {
            int item = this->get_space(i, j);
            if (item == 0)
            {
                std::cout << "   ";
            }
            else
            {
                std::cout << " " << item << " ";
            }
            if ((j + 1) % 3 == 0)
            {
                std::cout << "║";
            }
            else
            {
                std::cout << "│";
            }
        }
        std::cout << "\n";
        if ((i + 1) != 9)
        {
            if ((i + 1) % 3 == 0)
            {
                std::cout << "╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣";
            }
            else
            {
                std::cout << "╟───┼───┼───╫───┼───┼───╫───┼───┼───╢";
            }
            std::cout << "\n";
        }
    }
    std::cout << "╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝\n";
}