#include "raylib/raylib.h"
#include <stdbool.h>
#include "custom/page.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 500
#define MAX_FPS 60

int main(int argc, char *argv[]) {
  SetConfigFlags(FLAG_WINDOW_UNDECORATED);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "no");
  Page text = PageCreate();
  Font sex = LoadFont("../res/courer.ttf");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    // UPDATE
    PageUpdate(&text);

    // DRAW
    BeginDrawing();

    ClearBackground(GRAY);

    DrawText(TextFormat("fps : %d", GetFPS()), 10, SCREEN_HEIGHT - 20, 20,
             (Color){50, 50, 50, 255});
    DrawTextEx(sex, TextFormat("%s", text.content), (Vector2){20, 20}, 20, 0,
               RAYWHITE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
