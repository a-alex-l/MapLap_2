cmake_minimum_required(VERSION 3.15)
project(MapLap2_0)

set(CMAKE_CXX_STANDARD 17)
set(OpenCV_DIR /home/alex/opencv/build)

include_directories(include/ test/)

find_package(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(MapLap2_0
        src/main.cpp
        include/Line.hpp
        include/Circle.hpp
        include/LineDetector.hpp
        include/CircleDetector.hpp
        include/PointVector.hpp
        src/Line.cpp
        src/Circle.cpp
        src/LineDetector.cpp
        src/CircleDetector.cpp
        src/PointVector.cpp)

add_executable(MapLap2_0_Test
        include/Line.hpp
        include/Circle.hpp
        include/LineDetector.hpp
        include/CircleDetector.hpp
        include/PointVector.hpp
        src/Line.cpp
        src/Circle.cpp
        src/LineDetector.cpp
        src/CircleDetector.cpp
        src/PointVector.cpp
        test/Catch.hpp
        test/TestLine.cpp
        test/TestPointVector.cpp test/TestAll.cpp test/TestLine.cpp)


target_link_libraries(MapLap2_0 ${OpenCV_LIBS})