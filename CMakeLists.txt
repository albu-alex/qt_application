cmake_minimum_required(VERSION 3.19)
project(qt)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "D:\\qt\\5.15.2\\mingw81_64\\lib\\cmake")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)

find_package(Qt5Widgets REQUIRED)

add_executable(qt domain/programmer.cpp domain/programmer.h)

target_link_libraries(qt Qt5::Widgets)