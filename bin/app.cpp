#include <raylibs.h>

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
