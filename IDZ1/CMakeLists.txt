add_compile_options(-I${CMAKE_CURRENT_SOURCE_DIR}/../src)

file(GLOB SRC CONFIGURE_DEPENDS "../src/*.h" "../src/*.cpp")

set(CMAKE_CXX_STANDARD 20)

add_executable(IDZ1_task1 task1.cpp ${SRC})

add_executable(IDZ1_task3 task3.cpp ${SRC})

add_executable(IDZ1_task4 task4.cpp ${SRC})

add_executable(IDZ1_task5 task5.cpp ${SRC})
