cmake_minimum_required(VERSION 3.16)

include(Sdk/pico-sdk/pico_sdk_init.cmake)

include(Sdk/SdkConfig.cmake)

project(WifiManager)

pico_sdk_init()

add_link_options("-Wl,--print-memory-usage")

set(SOURCES)
set(INCLUDE_DIRS)

# To use Regex
# file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "Source/*.c")

add_subdirectory("Source")

add_executable(WifiManager ${SOURCES})

list(
    APPEND INCLUDE_DIRS
    # Do it, because there is lwipopts.h file in the Sdk directory, to configure lwIP stack.
    "${CMAKE_CURRENT_SOURCE_DIR}/Sdk"
)

include_directories(${INCLUDE_DIRS})

target_link_libraries(WifiManager pico_stdlib)

# from documentation: pico_cyw43_arch_none - If you do not need the TCP/IP stack but wish to use the on-board LED.
if(${PICO_BOARD} STREQUAL "pico_w")
    target_link_libraries(WifiManager pico_cyw43_arch_lwip_threadsafe_background)
endif()

pico_enable_stdio_usb(WifiManager 1)
pico_enable_stdio_uart(WifiManager 0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(WifiManager)
