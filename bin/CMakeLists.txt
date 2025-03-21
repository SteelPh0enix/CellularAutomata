add_executable(CellularAutomata app.cpp)
target_link_libraries(CellularAutomata PRIVATE raylib stdc++exp Window)
add_lib_includes(CellularAutomata)
enable_all_warnings(CellularAutomata)
