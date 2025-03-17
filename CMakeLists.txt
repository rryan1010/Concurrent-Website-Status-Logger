cmake_minimum_required(VERSION 3.10...3.21)
project(WebInfrastructureMonitor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

# Change this path to point to your Qt installation location.
set(CMAKE_PREFIX_PATH "/usr/local/.../qt/6.8.2/lib/cmake")

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