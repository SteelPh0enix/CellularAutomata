#include <raylib.h>

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
        ClearBackground(GetColor(0x123456FF));
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
