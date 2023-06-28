cmake_minimum_required(VERSION 3.25)
project(project2)

set(CMAKE_CXX_STANDARD 17)

add_executable(project2 main.cpp Point.cpp Point.hpp Line.cpp Line.hpp Fig.cpp Fig.hpp Graham.cpp Graham.hpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(D:/SFML-2.5.1/include)
target_link_libraries(project2 sfml-system sfml-window sfml-graphics sfml-audio)
