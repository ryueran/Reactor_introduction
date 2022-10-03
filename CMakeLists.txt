cmake_minimum_required(VERSION 3.5)

project(Event)

#add_executable(Event src/main.cpp)
find_package(Threads)

add_executable(Event_test src_test/main.cpp)

target_include_directories(Event_test PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src_test
    Threads::Threads
)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")