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

include_directories(domain)
include_directories(repository)
include_directories(service)
include_directories(gui)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/sources.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/programmers.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(qt
        domain/programmer.cpp
        domain/programmer.h
        domain/SourceFile.cpp
        domain/SourceFile.h
        repository/Repository.cpp
        repository/Repository.h
        repository/ProgrammerRepository.cpp
        repository/ProgrammerRepository.h
        repository/SourceFileRepository.cpp
        repository/SourceFileRepository.h
        service/Service.cpp
        service/Service.h
        gui/GUI.cpp
        gui/GUI.h
        gui/AbstractModel.cpp
        gui/AbstractModel.h main.cpp)

target_link_libraries(qt Qt5::Widgets)