#include <array>

class Sudoku {
   public:
    Sudoku();
    int get_space(int row, int col);
    void set_space(int row, int col, int value);
    std::array<std::array<int, 9>, 9> get_grid();
    std::array<int, 9> get_row(int row_index);
    std::array<int, 9> get_column(int column_index);
    std::array<int, 9> get_square(int square_index);
    void print();

   private:
    std::array<std::array<int, 9>, 9> initialize_grid();
    std::array<std::array<int, 9>, 9> grid;
};