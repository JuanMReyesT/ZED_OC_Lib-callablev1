#THIS FILE IS THE CMakeLists.txt you would use in your project 

cmake_minimum_required(VERSION 3.22.1)
project(hellofromZED)


find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


find_package(zed_open_capture REQUIRED)



add_executable(hellofromZED src/helloworld.cpp)
set_target_properties(hellofromZED PROPERTIES PREFIX "")
set_property(TARGET hellofromZED PROPERTY POSITION_INDEPENDENT_CODE ON)





target_link_libraries(hellofromZED
${OpenCV_LIBS})
target_link_libraries(hellofromZED 
zed_open_capture::zed_open_capture)
target_compile_definitions(hellofromZED PUBLIC VIDEO_MOD_AVAILABLE)
target_compile_definitions(hellofromZED PUBLIC SENSORS_MOD_AVAILABLE)
#(CMAKE_VERBOSE_MAKEFILE ON)