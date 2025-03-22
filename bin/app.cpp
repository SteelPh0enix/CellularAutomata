#include <raylib.h>

#include <Window/Window.hpp>
#include <optional>

int main() {
    setup_window(WindowConfig{
        .title = "Example GUI app",
        .minimalSize = {800, 600},
        .defaultSizeMultiplier = 0.75,
        .maxFps = std::nullopt,
        .monitor = 0,
    });

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(GetColor(0x123456FF));
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
