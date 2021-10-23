add_compile_options(-I${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(matrices task1.cpp src/matrix.cpp src/matrix.h src/fraction.cpp src/fraction.h src/matrix_row.cpp src/matrix_row.h src/gauss.cpp
        src/gauss.h)