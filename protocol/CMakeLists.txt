project(protocol)

add_library(${PROJECT_NAME} STATIC
        src/protocol.cpp
        src/data_entry.cpp
        src/data_types.cpp)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        fmt::fmt)

target_include_directories(${PROJECT_NAME} PUBLIC include)

add_subdirectory(tests)