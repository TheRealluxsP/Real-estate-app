cmake_minimum_required(VERSION 3.20)
project(DHMS)
set(CMAKE_CXX_STANDARD 17)

add_executable(DHMS main.cpp)

include_directories(Core)
add_subdirectory(Core)
add_subdirectory(CoreTests)
add_subdirectory(ConsoleApp)
add_subdirectory(RestAPI)

target_link_libraries(DHMS Core)