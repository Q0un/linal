add_executable(IDZ4_task1)
target_sources(IDZ4_task1
    PRIVATE
        task1.cpp
)
target_link_libraries(IDZ4_task1 PRIVATE lib)

add_executable(IDZ4_task2)
target_sources(IDZ4_task2
    PRIVATE
        task2.cpp
)
target_link_libraries(IDZ4_task2 PRIVATE lib)

add_executable(IDZ4_task3)
target_sources(IDZ4_task3
        PRIVATE
        task3.cpp
        )
target_link_libraries(IDZ4_task3 PRIVATE lib)