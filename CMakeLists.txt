cmake_minimum_required(VERSION 3.23)
project(project2)

set(CMAKE_CXX_STANDARD 17)

include_directories(/opt/homebrew/Cellar/sfml/2.5.1_2/include)
link_directories(/opt/homebrew/Cellar/sfml/2.5.1_2/lib)

add_executable(project2 main.cpp Point.cpp Point.hpp Line.cpp Line.hpp Fig.cpp Fig.hpp Graham.cpp Graham.hpp)

target_link_libraries(project2 sfml-graphics sfml-window sfml-system)