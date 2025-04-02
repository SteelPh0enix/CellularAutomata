// This is an "interface" header used to include raylib and raygui without compiler warnings
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wenum-compare"
#endif
#include <raygui.h>
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
