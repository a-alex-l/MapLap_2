cmake_minimum_required(VERSION 3.15)
project(MapLap2_0)

set(CMAKE_CXX_STANDARD 20)

include_directories(include/ test/)

set(OpenCV_DIR /home/alex/opencv/opencv/build)
find_package(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(MapLap2_0
        src/main.cpp

        include/detector/Line.hpp
        include/detector/Timer.hpp
        include/detector/Ellipse.hpp
        include/detector/Detector.hpp
        include/detector/Settings.hpp
        include/detector/BoolImage.hpp
        include/detector/PointVector.hpp
        include/detector/LineDetector.hpp
        include/detector/Preprocessing.hpp
        include/detector/EllipseDetector.hpp
        include/detector/TangentsDetector.hpp

        src/detector/Line.cpp
        src/detector/Timer.cpp
        src/detector/Ellipse.cpp
        src/detector/Detector.cpp
        src/detector/Settings.cpp
        src/detector/BoolImage.cpp
        src/detector/PointVector.cpp
        src/detector/LineDetector.cpp
        src/detector/Preprocessing.cpp
        src/detector/EllipseDetector.cpp
        src/detector/TangentsDetector.cpp)

add_executable(MapLap2_0_Test
        test/Catch.hpp
        test/TestAll.cpp
        test/TestLine.cpp
        test/TestFration.cpp
        test/TestPointVector.cpp
        test/TestPreprocessing.cpp

        include/detector/Line.hpp
        include/detector/Timer.hpp
        include/detector/Ellipse.hpp
        include/detector/Detector.hpp
        include/detector/Settings.hpp
        include/detector/BoolImage.hpp
        include/detector/PointVector.hpp
        include/detector/LineDetector.hpp
        include/detector/Preprocessing.hpp
        include/detector/EllipseDetector.hpp
        include/detector/TangentsDetector.hpp

        src/detector/Line.cpp
        src/detector/Timer.cpp
        src/detector/Ellipse.cpp
        src/detector/Detector.cpp
        src/detector/Settings.cpp
        src/detector/BoolImage.cpp
        src/detector/PointVector.cpp
        src/detector/LineDetector.cpp
        src/detector/Preprocessing.cpp
        src/detector/EllipseDetector.cpp
        src/detector/TangentsDetector.cpp)

target_link_libraries(MapLap2_0 ${OpenCV_LIBS})
target_link_libraries(MapLap2_0_Test ${OpenCV_LIBS})