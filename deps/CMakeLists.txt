include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)

FetchContent_Declare(
    raygui
    GIT_REPOSITORY https://github.com/raysan5/raygui.git
    GIT_TAG 4.0
)

function(add_raygui_includes target_name)
    # Define the include directory
    set(RAYGUI_INCLUDE_DIR "${FETCHCONTENT_BASE_DIR}/raygui-src/src")

    # Check if the target exists
    if(TARGET ${target_name})
        # Add the include directory to the target
        target_include_directories(${target_name} PRIVATE ${RAYGUI_INCLUDE_DIR})
        message(STATUS "Added include directory ${RAYGUI_INCLUDE_DIR} to target ${target_name}")
    else()
        message(FATAL_ERROR "Target ${target_name} does not exist.")
    endif()
endfunction()

FetchContent_MakeAvailable(raylib raygui)
