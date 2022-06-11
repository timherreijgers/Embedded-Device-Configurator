project(serial_tests)

add_executable(${PROJECT_NAME}
        serial.test.cpp)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        serial
        gtest_main
        gtest
        gmock)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})