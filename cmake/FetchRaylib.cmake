include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)

# using `target_link_library` should be preferred over this,
# use this only for interface libs.
function(add_raylib_includes target_name)
    set(RAYLIB_INCLUDE_DIR "${FETCHCONTENT_BASE_DIR}/raylib-src/src")
    if(TARGET ${target_name})
        target_include_directories(${target_name} INTERFACE ${RAYLIB_INCLUDE_DIR})
    else()
        message(FATAL_ERROR "Target ${target_name} does not exist.")
    endif()
endfunction()

FetchContent_MakeAvailable(raylib)
