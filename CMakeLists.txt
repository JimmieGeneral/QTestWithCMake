cmake_minimum_required(VERSION 3.25)
project(02_QTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH /home/generaldarknor/Qt/Qt5.12.12/5.12.12/gcc_64)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

# 包含子目录Src
include(Src/QTestWidget.cmake)

add_executable(02_QTest
                main.cpp
                ${QTestWidget})

target_link_libraries(02_QTest
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets)

