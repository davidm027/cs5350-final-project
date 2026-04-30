#include <cassert>
#include <iostream>

#include "sudoku.hpp"

Sudoku setup_valid_square() {
    Sudoku s;
    std::vector<std::vector<int>> squares{
        {1, 2, 6, 5, 9, 8, 7, 4, 3}, {7, 5, 8, 1, 4, 3, 9, 6, 2}, {9, 3, 4, 6, 7, 2, 8, 5, 1},
        {3, 1, 4, 2, 6, 9, 8, 7, 5}, {2, 9, 5, 8, 7, 4, 3, 1, 6}, {7, 6, 8, 5, 1, 3, 4, 2, 9},
        {9, 5, 7, 6, 3, 1, 4, 8, 2}, {4, 2, 1, 5, 8, 9, 6, 3, 7}, {3, 8, 6, 2, 4, 7, 1, 9, 5}};

    s.set_grid(squares);

    return s;
}

Sudoku setup_invalid_square_row() {
    Sudoku s;
    std::vector<std::vector<int>> squares{
        {1, 2, 6, 5, 9, 9, 7, 4, 3}, {7, 5, 8, 1, 4, 3, 9, 6, 2}, {9, 3, 4, 6, 7, 2, 8, 5, 1},
        {3, 1, 4, 2, 6, 9, 8, 7, 5}, {2, 9, 5, 8, 7, 4, 3, 1, 6}, {7, 6, 8, 5, 1, 3, 4, 2, 9},
        {9, 5, 7, 6, 3, 1, 4, 8, 2}, {4, 2, 1, 5, 8, 9, 6, 3, 7}, {3, 8, 6, 2, 4, 7, 1, 9, 5}};

    s.set_grid(squares);

    return s;
}

Sudoku setup_invalid_square_col() {
    Sudoku s;
    std::vector<std::vector<int>> squares{
        {1, 2, 6, 5, 9, 8, 7, 4, 3}, {7, 5, 8, 1, 4, 3, 9, 6, 2}, {9, 3, 4, 6, 7, 2, 8, 5, 1},
        {3, 1, 4, 2, 6, 9, 8, 7, 5}, {2, 9, 5, 8, 7, 4, 3, 1, 6}, {7, 6, 8, 5, 1, 4, 4, 2, 9},
        {9, 5, 7, 6, 3, 1, 4, 8, 2}, {4, 2, 1, 5, 8, 9, 6, 3, 7}, {3, 8, 6, 2, 4, 7, 1, 9, 5}};

    s.set_grid(squares);

    return s;
}

Sudoku setup_invalid_square_section() {
    Sudoku s;
    std::vector<std::vector<int>> squares{
        {1, 2, 6, 5, 9, 8, 7, 4, 3}, {7, 5, 8, 1, 4, 3, 9, 6, 2}, {9, 3, 4, 6, 7, 2, 8, 5, 1},
        {3, 1, 4, 2, 6, 9, 8, 7, 5}, {2, 9, 5, 8, 7, 4, 3, 1, 6}, {7, 6, 8, 5, 1, 3, 4, 2, 9},
        {9, 5, 7, 6, 3, 1, 4, 8, 2}, {4, 2, 1, 5, 4, 9, 6, 3, 7}, {3, 8, 6, 2, 4, 7, 1, 9, 5}};

    s.set_grid(squares);

    return s;
}

void test_get_space() {
    std::cout << "Testing s.get_space()...\n";

    Sudoku s = setup_valid_square();
    int a = s.get_space(0, 0);
    assert(a == 1 && "Expected a to be 1.");

    int b = s.get_space(3, 4);
    assert(b == 9 && "Expected b to be 9.");

    int c = s.get_space(8, 8);
    assert(c == 5 && "Expected c to be 1.");

    std::cout << "Completed s.get_space() tests.\n";
}

void test_set_space() {
    std::cout << "Testing s.set_space()...\n";

    Sudoku s = setup_valid_square();
    s.set_space(0, 0, 5);
    int a = s.get_space(0, 0);
    assert(a == 5 && "Expected a to be 5 after setting space.");

    s.set_space(3, 4, 1);
    int b = s.get_space(3, 4);
    assert(b == 1 && "Expected b to be 0 after setting space.");

    s.set_space(8, 8, 8);
    int c = s.get_space(8, 8);
    assert(c == 8 && "Expected c to be 8 after setting space.");

    std::cout << "Completed s.set_space() tests.\n";
}

void test_get_row() {
    std::cout << "Testing s.get_row()...\n";

    Sudoku s = setup_valid_square();
    std::array<int, 9> a = s.get_row(0);
    std::array<int, 9> a_expected{1, 2, 6, 7, 5, 8, 9, 3, 4};
    assert(a == a_expected && "Expected both arrays to be equal.");

    std::array<int, 9> b = s.get_row(3);
    std::array<int, 9> b_expected{3, 1, 4, 2, 9, 5, 7, 6, 8};
    assert(b == b_expected && "Expected both arrays to be equal.");

    std::array<int, 9> c = s.get_row(8);
    std::array<int, 9> c_expected{4, 8, 2, 6, 3, 7, 1, 9, 5};
    assert(c == c_expected && "Expected both arrays to be equal.");

    std::cout << "Completed s.get_row() tests.\n";
}

void test_get_column() {
    std::cout << "Testing s.get_column()...\n";

    Sudoku s = setup_valid_square();
    std::array<int, 9> a = s.get_column(0);
    std::array<int, 9> a_expected{1, 5, 7, 3, 2, 8, 9, 6, 4};
    assert(a == a_expected && "Expected both arrays to be equal.");

    std::array<int, 9> b = s.get_column(3);
    std::array<int, 9> b_expected{7, 1, 9, 2, 8, 3, 4, 5, 6};
    assert(b == b_expected && "Expected both arrays to be equal.");

    std::array<int, 9> c = s.get_column(8);
    std::array<int, 9> c_expected{4, 2, 1, 8, 3, 9, 6, 7, 5};
    assert(c == c_expected && "Expected both arrays to be equal.");

    std::cout << "Completed s.get_column() tests.\n";
}

void test_get_square() {
    std::cout << "Testing s.get_square()...\n";

    Sudoku s = setup_valid_square();
    std::array<int, 9> a = s.get_square(0);
    std::array<int, 9> a_expected{1, 2, 6, 5, 9, 8, 7, 4, 3};
    assert(a == a_expected && "Expected both arrays to be equal.");

    std::array<int, 9> b = s.get_square(3);
    std::array<int, 9> b_expected{3, 1, 4, 2, 6, 9, 8, 7, 5};
    assert(b == b_expected && "Expected both arrays to be equal.");

    std::array<int, 9> c = s.get_square(8);
    std::array<int, 9> c_expected{3, 8, 6, 2, 4, 7, 1, 9, 5};
    assert(c == c_expected && "Expected both arrays to be equal.");

    std::cout << "Completed s.get_square() tests.\n";
}

void test_set_square() {
    std::cout << "Testing s.set_square()...\n";

    Sudoku s = setup_valid_square();
    std::vector<int> values{2, 9, 5, 8, 7, 4, 3, 1, 6};
    s.set_square(0, values);

    std::array<int, 9> a = s.get_square(0);
    std::array<int, 9> a_expected{2, 9, 5, 8, 7, 4, 3, 1, 6};
    assert(a == a_expected && "Expected both arrays to be equal.");

    std::cout << "Completed s.set_square() tests.\n";
}

void test_valid_square() {
    std::cout << "Testing valid square...\n";

    Sudoku s = setup_valid_square();
    assert(s.is_valid() == 1 && "Expected square.is_valid() to be true, got false instead.");

    std::cout << "Completed valid square tests.\n";
}

void test_invalid_square_row() {
    std::cout << "Testing row-invalid square...\n";

    Sudoku s = setup_invalid_square_row();
    assert(s.is_valid() == 0 && "Expected square.is_valid() to be true, got false instead.");

    std::cout << "Completed row-invalid square tests.\n";
}

void test_invalid_square_col() {
    std::cout << "Testing column-invalid square...\n";

    Sudoku s = setup_invalid_square_col();
    assert(s.is_valid() == 0 && "Expected square.is_valid() to be true, got false instead.");

    std::cout << "Completed column-invalid square tests.\n";
}

void test_invalid_square_section() {
    std::cout << "Testing section-invalid square...\n";

    Sudoku s = setup_invalid_square_section();
    assert(s.is_valid() == 0 && "Expected square.is_valid() to be true, got false instead.");

    std::cout << "Completed section-invalid square tests.\n";
}

void run_tests() {
    test_get_space();
    test_set_space();
    test_get_space();
    test_get_column();
    test_get_square();
    test_set_square();
    test_valid_square();
    test_invalid_square_row();
    test_invalid_square_col();
    test_invalid_square_section();
}