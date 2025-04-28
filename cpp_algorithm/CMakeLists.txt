cmake_minimum_required(VERSION 3.0)
project(Algorithm_learning)

set(CMAKE_CXX_STANDARD 11)

# 包含头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/first_class)
include_directories(${PROJECT_SOURCE_DIR}/second_class)

add_subdirectory(first_class)
add_subdirectory(second_class)


add_executable(sort_test src/sort_test.cpp)
add_executable(odd_find src/odd_find_test.cpp)
add_executable(small_sum src/small_sum_test.cpp)


target_link_libraries(sort_test first_class second_class)
target_link_libraries(odd_find first_class)
target_link_libraries(small_sum second_class)
