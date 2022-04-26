cmake_minimum_required(VERSION 3.16)

project(Embedded-device-configurator)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_INSTALL_PREFIX "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

enable_testing()

#find_package(GTest)
#find_package(GMock)
#find_package(fmt)
find_package(CopperSpice)

add_subdirectory(interface)