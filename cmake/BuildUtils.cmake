function(enable_all_warnings target)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_compile_options(${target} PRIVATE
            -Wall            # Enable all the common warnings
            -Wextra          # Enable some extra warnings
            -pedantic        # Enable (almost) all remaining warnings
        )
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        target_compile_options(${target} PRIVATE
            /W4            # Enable the maximum warning level
        )
    endif()
endfunction()

function(add_lib_includes target)
    target_include_directories(${target} PUBLIC ${CMAKE_SOURCE_DIR}/lib)
endfunction()
