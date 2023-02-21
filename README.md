[![Build](https://github.com/HouseSimOn/PicoWifiManager/actions/workflows/build_cmake.yml/badge.svg)](https://github.com/HouseSimOn/PicoWifiManager/actions/workflows/build_cmake.yml)

# Pico Wifi Manager
WiFi Manager for Pico W.

## Repository template
Repository created based on [this template](https://github.com/HouseSimOn/PicoSdkStartTemplate) in version __0.0.1__.

# SDK Documentation
https://raspberrypi.github.io/pico-sdk-doxygen/modules.html

## SetupSd  

Platform: Ubuntu

1. Clone repository.
2. Call `git submodule update --init` in the main directory and then go to the pico-sdk and call this command again. (or `git submodule update --init --recursive`)

### printf - via USB
1. To CMakeLists.txt add following lines:
    ```
    pico_enable_stdio_usb(PicoSdkStartTemplate 1)
    pico_enable_stdio_uart(PicoSdkStartTemplate 0)
    ```
2. Find connected device: `ls -l /dev/ttyUSB* /dev/ttyACM*`
3. Start minicom: `sudo minicom -b 115200 -o -D /dev/ttyACM0` 

