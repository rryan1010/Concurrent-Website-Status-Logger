# Web Infrastructure Monitor

Web Infrastructure Monitor is a modern C++ application with a Qt-based GUI that monitors the status of critical websites. It periodically checks if websites such as Google, Meta, Apple, Microsoft, and Amazon (as well as user-specified websites) are online by performing efficient HTTP HEAD requests using libcurl. The project demonstrates advanced C++ features including multithreading, network programming, and a user-friendly graphical interface using Qt 6.

## Features

- **Real-Time Monitoring:** Periodically refreshes the status of each website every 5 seconds.
- **Multithreaded Checks:** Utilizes C++ threads for concurrent network checks for improved performance.
- **Dynamic List Management:** Easily add or remove websites from the monitoring list via the GUI.
- **Modern GUI:** A polished Qt 6 interface displays website statuses in a clear table format.
- **Cross-Platform:** Designed to compile and run on macOS, Linux, and Windows (with appropriate Qt and libcurl installations).

## Prerequisites

- **C++ Compiler:** A C++17 compliant compiler.
- **CMake:** Version 3.10 or later.
- **Qt 6:** The project uses Qt 6 Widgets. Install Qt 6 via the official installer or Homebrew on macOS.
- **libcurl:** Installed with development headers.

- **Side Note:** Please change the Qt Path in the CMakeLists.txt file.


### On macOS (example using Homebrew):

```bash
brew install qt
brew install curl