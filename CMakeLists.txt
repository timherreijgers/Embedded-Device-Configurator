cmake_minimum_required(VERSION 3.16)

project(Embedded-device-configurator)

set(CMAKE_CXX_STANDARD 23)

enable_testing()

#add_subdirectory(third-party/copperspice)

#find_package(GTest)
#find_package(GMock)
#find_package(fmt)
find_package(CopperSpice)

add_subdirectory(interface)