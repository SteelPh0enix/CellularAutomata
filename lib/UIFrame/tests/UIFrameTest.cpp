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

#include <print>

void setup_main_window() {
    constexpr int minimalWindowWidth{800};
    constexpr int minimalWindowHeight{600};
    constexpr double appWindowSizeMultiplier{0.9};

    InitWindow(minimalWindowWidth, minimalWindowHeight, "Cellular automata by SteelPh0enix");

    auto const currentMonitor = GetCurrentMonitor();
    auto const currentMonitorWidth = GetMonitorWidth(currentMonitor);
    auto const currentMonitorHeight = GetMonitorHeight(currentMonitor);
    auto const maxFramerate = GetMonitorRefreshRate(currentMonitor);

    std::println("Current monitor resolution: {}x{}@{}Hz", currentMonitorWidth,
                 currentMonitorHeight, maxFramerate);

    auto const appWindowWidth =
        static_cast<int>(static_cast<double>(currentMonitorWidth) * appWindowSizeMultiplier);
    auto const appWindowHeight =
        static_cast<int>(static_cast<double>(currentMonitorHeight) * appWindowSizeMultiplier);
    auto const appWindowX = (currentMonitorWidth - appWindowWidth) / 2;
    auto const appWindowY = (currentMonitorHeight - appWindowHeight) / 2;

    std::println("Desired app window size: {}x{}, placed at {}x{}", appWindowWidth, appWindowHeight,
                 appWindowX, appWindowY);

    SetWindowMinSize(minimalWindowWidth, minimalWindowHeight);
    SetWindowSize(appWindowWidth, appWindowHeight);
    SetWindowPosition(appWindowX, appWindowY);
    SetTargetFPS(maxFramerate);
}

int main() {
    setup_main_window();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
