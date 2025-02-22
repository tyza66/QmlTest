cmake_minimum_required(VERSION 3.16)

project(twowindows VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(apptwowindows
    main.cpp
    mainwindow.cpp
    newwindow.cpp
)

set_target_properties(apptwowindows PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_include_directories(apptwowindows PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(apptwowindows PRIVATE Qt6::Widgets)

include(GNUInstallDirs)
install(TARGETS apptwowindows
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
