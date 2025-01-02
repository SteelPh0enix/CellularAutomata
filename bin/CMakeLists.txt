add_executable(HelloWorld app.cpp)
target_link_libraries(HelloWorld PRIVATE raylib stdc++exp)
add_raygui_includes(HelloWorld)
enable_all_warnings(HelloWorld)
