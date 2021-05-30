cmake_minimum_required(VERSION 3.0.2)
project(reeds_shepp)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
add_compile_options(-std=c++14)

add_library(reeds_shepp reeds_shepp.cpp)
add_library(c_reeds_shepp SHARED wrapper.cpp)
target_link_libraries(c_reeds_shepp reeds_shepp)

install(TARGETS c_reeds_shepp CONFIGURATIONS Release LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX})
