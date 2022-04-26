project(interface)

#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)

add_executable(EmbeddedDeviceConfigurator
        src/main.cpp)

target_link_libraries(EmbeddedDeviceConfigurator PRIVATE
        CopperSpice::CsGui
        CopperSpice::CsCore)

if(MSVC)
    # replace /Zx with /Z7 for tooling compatibility (Incredibuild and stashed.io)
    string(REGEX REPLACE "/Z[iI7]" "/Z7" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    string(REGEX REPLACE "/Z[iI7]" "/Z7" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")

    string (REGEX REPLACE "/W3" "/W4" CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}"  )
    string (REGEX REPLACE "/W3" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    string (REGEX REPLACE ".INCREMENTAL[:NO]*" "/INCREMENTAL:NO" CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS_DEBUG}")
else()
    # Linux, Windows (MinGW)
    set(CMAKE_EXE_LINKER_FLAGS    "${CMAKE_EXE_LINKER_FLAGS}    -Wl,--no-undefined")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")
    set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Wl,--no-undefined")
endif()

set(CMAKE_INSTALL_RPATH ".")

if(MSVC)
    target_link_options(EmbeddedDeviceConfigurator PRIVATE
            /SUBSYSTEM:WINDOWS
            )
endif()

install(TARGETS EmbeddedDeviceConfigurator DESTINATION ${CMAKE_INSTALL_PREFIX})

cs_copy_library(CsGui)
cs_copy_library(CsCore)
cs_copy_plugins(CsGui)