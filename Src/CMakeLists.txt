add_executable(02_QTest
        QTestWidget.cpp
        QTestWidget.ui
        main.cpp)

target_link_libraries(02_QTest PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets)