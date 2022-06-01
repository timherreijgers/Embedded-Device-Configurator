project(interface)

COPPERSPICE_RESOURCES(
        ${CMAKE_CURRENT_SOURCE_DIR}/src/mainwindow.ui
)

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(CMAKE_INSTALL_RPATH "@executable_path")
elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD)")
    set(CMAKE_INSTALL_RPATH "\$ORIGIN")
endif()

add_executable(EmbeddedDeviceConfigurator
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.ui
        src/protocol_table_item_model.cpp)

target_include_directories(EmbeddedDeviceConfigurator PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
        )

target_link_libraries(EmbeddedDeviceConfigurator PRIVATE
        CopperSpice::CsGui
        CopperSpice::CsCore
        fmt::fmt)

install(TARGETS EmbeddedDeviceConfigurator RUNTIME DESTINATION .)

cs_copy_library(CsGui)
cs_copy_library(CsCore)
cs_copy_plugins(CsGui)