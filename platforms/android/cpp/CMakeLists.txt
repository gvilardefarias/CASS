cmake_minimum_required(VERSION 3.4.1)
add_library(cordova-cpp-bridge-lib SHARED CDVCppBridge.cpp)
target_link_libraries(cordova-cpp-bridge-lib log)