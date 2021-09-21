cmake_minimum_required(VERSION 3.1.0)

 project(IM VERSION 1.0.0 LANGUAGES CXX)

 set(CMAKE_CXX_STANDARD 11)
 set(CMAKE_CXX_STANDARD_REQUIRED ON)

 set(CMAKE_AUTOMOC ON)
 set(CMAKE_AUTORCC ON)
 set(CMAKE_AUTOUIC ON)
 set(Qt5_DIR "D:/Qt/5.15.2/msvc2019_64/lib/cmake/Qt5")
 if(CMAKE_VERSION VERSION_LESS "3.7.0")
     set(CMAKE_INCLUDE_CURRENT_DIR ON)
 endif()

 find_package(Qt5 COMPONENTS Widgets REQUIRED)

 add_executable(IM
     net/TCPNet.cpp
     net/EventDispatch.cpp
     net/EventHandle.cpp
     ui/Login.cpp
     main.cpp
 )

 qt5_wrap_ui(ui_list 
    "ui/login.ui"
 )

 target_link_libraries(IM Qt5::Widgets)