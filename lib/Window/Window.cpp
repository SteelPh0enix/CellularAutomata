#include "Window.hpp"

#include <spdlog/spdlog.h>

void setup_window(WindowConfig const& config) {
    InitWindow(config.minimalSize.width, config.minimalSize.height, config.title.c_str());

    auto const selectedMonitor =
        config.monitor.has_value() ? config.monitor.value() : GetCurrentMonitor();
    auto const maxFramerate =
        config.maxFps.has_value() ? config.maxFps.value() : GetMonitorRefreshRate(selectedMonitor);
    auto const selectedMonitorWidth = GetMonitorWidth(selectedMonitor);
    auto const selectedMonitorHeight = GetMonitorHeight(selectedMonitor);

    auto const appWindowWidth =
        static_cast<int>(static_cast<double>(selectedMonitorWidth) * config.defaultSizeMultiplier);
    auto const appWindowHeight =
        static_cast<int>(static_cast<double>(selectedMonitorHeight) * config.defaultSizeMultiplier);
    auto const appWindowX = (selectedMonitorWidth - appWindowWidth) / 2;
    auto const appWindowY = (selectedMonitorHeight - appWindowHeight) / 2;

    auto const currentMonitorPosition = GetMonitorPosition(selectedMonitor);
    auto const appWindowGlobalX = appWindowX + currentMonitorPosition.x;
    auto const appWindowGlobalY = appWindowY + currentMonitorPosition.y;

    spdlog::info("Selected monitor {}, {} FPS, {}x{}", selectedMonitor, maxFramerate,
                 selectedMonitorWidth, selectedMonitorHeight);
    spdlog::info("Current monitor position: {}x{}", currentMonitorPosition.x,
                 currentMonitorPosition.y);
    spdlog::info("Creating a window with dimensions {}x{} at {}, {}", appWindowWidth,
                 appWindowHeight, appWindowGlobalX, appWindowGlobalY);

    SetWindowMonitor(selectedMonitor);
    SetWindowMinSize(config.minimalSize.width, config.minimalSize.height);
    SetWindowSize(appWindowWidth, appWindowHeight);
    SetWindowPosition(appWindowGlobalX, appWindowGlobalY);
    SetTargetFPS(maxFramerate);
}
