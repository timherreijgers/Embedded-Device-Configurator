project(interface)

COPPERSPICE_RESOURCES(
        ${CMAKE_CURRENT_SOURCE_DIR}/src/mainwindow.ui
)

set(CMAKE_INSTALL_RPATH "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

add_executable(EmbeddedDeviceConfigurator
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.ui src/protocol_table_item_model.cpp)

target_include_directories(EmbeddedDeviceConfigurator PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
        )

target_link_libraries(EmbeddedDeviceConfigurator PRIVATE
        CopperSpice::CsGui
        CopperSpice::CsCore
        gtest_main
        gtest
        gmock
        fmt::fmt)

if(MSVC)
    target_link_options(EmbeddedDeviceConfigurator PRIVATE
            /SUBSYSTEM:WINDOWS
            )
endif()

install(TARGETS EmbeddedDeviceConfigurator RUNTIME DESTINATION .)

cs_copy_library(CsGui)
cs_copy_library(CsCore)
cs_copy_plugins(CsGui)