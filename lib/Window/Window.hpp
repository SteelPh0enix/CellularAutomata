#pragma once
#include <raylib.h>

#include <optional>
#include <string>

struct WindowSize {
    int width;
    int height;
};

struct WindowConfig {
    std::string title;
    WindowSize minimalSize;
    // default window size is monitor size times the multiplier below
    double defaultSizeMultiplier;
    std::optional<int> maxFps;
    std::optional<int> monitor;
};

constexpr void setup_window(WindowConfig const& config) {
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

    SetWindowMonitor(selectedMonitor);
    SetWindowMinSize(config.minimalSize.width, config.minimalSize.height);
    SetWindowSize(appWindowWidth, appWindowHeight);
    SetWindowPosition(appWindowX, appWindowY);
    SetTargetFPS(maxFramerate);
}
