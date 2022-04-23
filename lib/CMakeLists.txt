add_library(lib STATIC)

target_sources(lib
        PRIVATE
        impl/extended_matrix.cpp
        impl/fraction.cpp
        impl/gauss.cpp
        impl/matrix.cpp
        impl/matrix_row.cpp
        impl/matrix_utils.cpp
        impl/permutation.cpp
        impl/permutation_utils.cpp
        impl/poly.cpp)

target_include_directories(lib
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/impl)
