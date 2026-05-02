#pragma once

#include <array>
#include <vector>


class Sudoku
{
   public:
    Sudoku();
    int get_space(int row, int col);
    void set_space(int row, int col, int value);
    std::array<std::array<int, 9>, 9> get_grid();
    std::array<int, 9> get_row(int row_index);
    std::array<int, 9> get_column(int column_index);
    std::array<int, 9> get_square(int square_index);
    bool is_choice_valid(int row, int col, int value);
    void set_square(int square_index, std::vector<int> values);
    void set_grid(std::vector<std::vector<int>> values);
    bool is_valid();
    void print();
    // int unique(int, int );

   private:
    std::array<std::array<int, 9>, 9> initialize_grid();
    std::array<std::array<int, 9>, 9> grid;
    static bool contains(const std::array<int, 9>& arr, int val);
    static int find_square(int row, int col);
};