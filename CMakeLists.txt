cmake_minimum_required(VERSION 3.16)

project(Embedded-device-configurator)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_INSTALL_DIRECTORY ${CMAKE_BINARY_DIR}/deploy)

set(CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_DIRECTORY}")

enable_testing()

add_subdirectory(third-party/googletest)
add_subdirectory(third-party/fmt)

# TODO: Try to fix this using ExternalProject_Add https://cmake.org/cmake/help/latest/module/ExternalProject.html
find_package(CopperSpice REQUIRED)

add_subdirectory(interface)
add_subdirectory(protocol)