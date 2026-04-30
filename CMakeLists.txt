cmake_minimum_required(VERSION 3.16)

project(FinalProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

find_package(OpenMP REQUIRED)
find_package(MPI REQUIRED)
find_package(Boost CONFIG REQUIRED COMPONENTS program_options)

# add_subdirectory(src)
add_executable(FinalProject
    main.cpp
    sudoku.cpp
    solvers.cpp
)

target_include_directories(FinalProject PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(FinalProject PRIVATE ${OpenMP_CXX_FLAGS})

target_link_libraries(FinalProject
    PRIVATE
    ${OpenMP_CXX_FLAGS}
    ${OpenMP_CXX_LIBRARIES}
    MPI::MPI_CXX
    Boost::program_options
)