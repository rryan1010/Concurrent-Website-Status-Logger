
---

### Source Code Files

The rest of the files are as provided in the previous sections. For completeness, here are the file summaries:

- **main.cpp:**  
  *(See previous section)*

- **MainWindow.h / MainWindow.cpp:**  
  *(Contains high-level GUI class implementation)*

- **Monitor.h / Monitor.cpp:**  
  *(Contains website management and multithreaded checking functionality)*

- **WebChecker.h / WebChecker.cpp:**  
  *(Performs the network checks via libcurl)*

- **CMakeLists.txt:**  
  *(See below)*

#### CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.10...3.21)
project(WebInfrastructureMonitor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

# Adjust this path to your Qt6 installation directory.
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt/lib/cmake")
# For Intel macOS via Homebrew, use:
# set(CMAKE_PREFIX_PATH "/usr/local/opt/qt/lib/cmake")

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
