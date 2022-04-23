add_executable(IDZ2_task1)
target_sources(IDZ2_task1
    PRIVATE
        task1.cpp
)
target_link_libraries(IDZ2_task1 PRIVATE lib)

add_executable(IDZ2_task2)
target_sources(IDZ2_task2
    PRIVATE
        task2.cpp
)
target_link_libraries(IDZ2_task2 PRIVATE lib)

add_executable(IDZ2_task3)
target_sources(IDZ2_task3
    PRIVATE
        task3.cpp
)
target_link_libraries(IDZ2_task3 PRIVATE lib)

add_executable(IDZ2_task4)
target_sources(IDZ2_task4
    PRIVATE
        task4.cpp
)
target_link_libraries(IDZ2_task4 PRIVATE lib)

add_executable(IDZ2_task5)
target_sources(IDZ2_task5
    PRIVATE
        task5.cpp
)
target_link_libraries(IDZ2_task5 PRIVATE lib)
