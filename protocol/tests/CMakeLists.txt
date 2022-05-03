project(protocol_tests)

add_executable(${PROJECT_NAME}
        protocol.test.cpp
        protocol_configured.test.cpp)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        protocol
        gtest_main
        gtest
        gmock)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})