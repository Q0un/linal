add_executable(IDZ1_task1)
target_sources(IDZ1_task1
    PRIVATE
        task1.cpp
)
target_link_libraries(IDZ1_task1 PRIVATE lib)

add_executable(IDZ1_task3)
target_sources(IDZ1_task3
    PRIVATE
        task3.cpp
)
target_link_libraries(IDZ1_task3 PRIVATE lib)

add_executable(IDZ1_task4)
target_sources(IDZ1_task4
    PRIVATE
        task4.cpp
)
target_link_libraries(IDZ1_task4 PRIVATE lib)

add_executable(IDZ1_task5)
target_sources(IDZ1_task5
    PRIVATE
        task5.cpp
)
target_link_libraries(IDZ1_task5 PRIVATE lib)
