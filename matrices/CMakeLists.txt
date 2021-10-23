add_compile_options(-I${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB matrices_SRC CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")

add_executable(matrices_task1 task1.cpp ${matrices_SRC})

add_executable(matrices_task3 task3.cpp ${matrices_SRC})

add_executable(matrices_task5 task5.cpp ${matrices_SRC})
