cmake_minimum_required(VERSION 3.10...3.21)
project(WebInfrastructureMonitor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

# Change this path to your Qt6 installation directory.
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt/lib/cmake")
# For Intel macOS via Homebrew, use:
set(CMAKE_PREFIX_PATH "/usr/local/opt/qt/lib/cmake")
## IF EITHER DO NOT WORK, SIMPLY PASTE THE PATH TO CMAKE IN YOUR QT6 INSTALLATION FOLDER

find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(CURL REQUIRED)

add_executable(WebInfrastructureMonitor
    main.cpp
    MainWindow.cpp
    Monitor.cpp
    WebChecker.cpp
    MainWindow.h
    Monitor.h
    WebChecker.h
)

target_link_libraries(WebInfrastructureMonitor Qt6::Widgets CURL::libcurl)