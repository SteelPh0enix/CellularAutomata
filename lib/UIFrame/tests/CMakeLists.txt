add_executable(UIFrameTest UIFrameTest.cpp)
target_link_libraries(UIFrameTest PRIVATE raylib stdc++exp UIFrame)
add_raygui_includes(UIFrameTest)
enable_all_warnings(UIFrameTest)
