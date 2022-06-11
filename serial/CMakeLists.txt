project(serial)

add_library(${PROJECT_NAME} STATIC
        src/serial.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

add_subdirectory(tests)
