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

int main() {
  InitWindow(400, 200, "raygui - controls test suite");
  SetTargetFPS(60);

  bool showMessageBox = false;

  while (!WindowShouldClose()) {
    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();
    ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

    const auto buttonRect = Rectangle(24, 24, 120, 30);
    if (GuiButton(buttonRect, "#191#Show Message"))
      showMessageBox = true;

    if (showMessageBox) {
      const auto msgBoxRect = Rectangle(85, 70, 250, 100);
      int result = GuiMessageBox(msgBoxRect, "#191#Message Box",
                                 "Hi! This is a message!", "Nice;Cool");

      if (result >= 0)
        showMessageBox = false;
    }

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
