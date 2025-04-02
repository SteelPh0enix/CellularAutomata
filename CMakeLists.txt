cmake_minimum_required(VERSION 3.28)
project(RaylibHelloWorld LANGUAGES C CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Setting build type to 'Release' as none was specified.")
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

include("SetLanguageStandard")
include("BuildUtils")
include("FetchRaylib")
include("FetchRaygui")
include("FetchSpdlog")

add_subdirectory("lib")
add_subdirectory("bin")
