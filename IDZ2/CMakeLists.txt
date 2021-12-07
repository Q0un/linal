add_compile_options(-I${CMAKE_CURRENT_SOURCE_DIR}/../src)

file(GLOB SRC CONFIGURE_DEPENDS "../src/*.h" "../src/*.cpp")

set(CMAKE_CXX_STANDARD 20)

add_executable(IDZ2_task1 task1.cpp ${SRC})
add_executable(IDZ2_task2 task2.cpp ${SRC})
add_executable(IDZ2_task3 task3.cpp ${SRC})
