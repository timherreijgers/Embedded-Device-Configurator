project(interface)

set(CMAKE_INSTALL_RPATH "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

add_executable(EmbeddedDeviceConfigurator
        src/main.cpp)

target_link_libraries(EmbeddedDeviceConfigurator PRIVATE
        CopperSpice::CsGui
        CopperSpice::CsCore)

if(MSVC)
    target_link_options(EmbeddedDeviceConfigurator PRIVATE
            /SUBSYSTEM:WINDOWS
            )
endif()

install(TARGETS EmbeddedDeviceConfigurator RUNTIME DESTINATION .)

cs_copy_library(CsGui)
cs_copy_library(CsCore)
cs_copy_plugins(CsGui)