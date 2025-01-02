cmake_minimum_required(VERSION 3.28)
project(RaylibHelloWorld LANGUAGES C CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include("SetLanguageStandard")
include("BuildUtils")

add_subdirectory("deps")
add_subdirectory("bin")
