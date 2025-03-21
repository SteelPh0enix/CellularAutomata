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

void setup_window(WindowConfig const& config);
