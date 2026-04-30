#include <array>

class Sudoku {
   public:
    Sudoku();
    int get_square(int row, int col);
    void set_square(int row, int col, int value);
    std::array<std::array<int, 9>, 9> get_grid();
    void print();

   private:
    std::array<std::array<int, 9>, 9> initialize_grid();
    std::array<std::array<int, 9>, 9> grid;
};