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

#include <Window/Window.hpp>
#include <optional>

int main() {
    setup_window(WindowConfig{
        .title = "Cellular Automata by SteelPh0enix",
        .minimalSize = {800, 600},
        .defaultSizeMultiplier = 0.75,
        .maxFps = std::nullopt,
        .monitor = std::nullopt,
    });

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
