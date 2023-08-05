cmake_minimum_required(VERSION 3.25)
project(02_QTest CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH /home/generaldarknor/Qt/Qt5.12.12/5.12.12/gcc_64)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS REQUIRED Core Gui Widgets)

add_subdirectory(Src)