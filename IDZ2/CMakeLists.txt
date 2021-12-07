add_compile_options(-I${CMAKE_CURRENT_SOURCE_DIR}/../src)

file(GLOB SRC CONFIGURE_DEPENDS "../src/*.h" "../src/*.cpp")

set(CMAKE_CXX_STANDARD 20)

