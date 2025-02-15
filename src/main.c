#include "raylib/raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 500

int main(int argc, char *argv[]) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "no");

  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    // UPDATE

    //----------------------------------------------------------------------------------

    // DRAW
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("racist bad", 190, 200, 20,
             LIGHTGRAY);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
