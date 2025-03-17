
---

### Source Code Files

The rest of the files are as provided in the previous sections. For completeness, here are the file summaries:

- **main.cpp:**  
  *(Driver class)*

- **MainWindow.h / MainWindow.cpp:**  
  *(Contains high-level GUI class implementation)*

- **Monitor.h / Monitor.cpp:**  
  *(Contains multithreaded checking functionality with website management)*

- **WebChecker.h / WebChecker.cpp:**  
  *(Performs network checks via libcurl)*

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
set(CMAKE_PREFIX_PATH "/usr/local/opt/qt/lib/cmake")

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
```

MIT License

Copyright (c) 2025 RYAN RIM

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights 
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
copies of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in 
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
THE SOFTWARE.
