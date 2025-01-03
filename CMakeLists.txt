cmake_minimum_required(VERSION 3.28)
project(RaylibHelloWorld LANGUAGES C CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include("SetLanguageStandard")
include("BuildUtils")
include("FetchRaylib")
include("FetchRaygui")

add_subdirectory("lib")
add_subdirectory("bin")
