include(FetchContent)

FetchContent_Declare(
    raygui
    GIT_REPOSITORY https://github.com/raysan5/raygui.git
    GIT_TAG 4.0
)

function(add_raygui_includes target_name)
    set(RAYGUI_INCLUDE_DIR "${FETCHCONTENT_BASE_DIR}/raygui-src/src")
    if(TARGET ${target_name})
        target_include_directories(${target_name} PRIVATE ${RAYGUI_INCLUDE_DIR})
    else()
        message(FATAL_ERROR "Target ${target_name} does not exist.")
    endif()
endfunction()

FetchContent_MakeAvailable(raygui)
