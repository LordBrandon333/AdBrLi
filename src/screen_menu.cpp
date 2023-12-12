#include "raylib.h"

void screen_menu(){
    DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 200, RED);
    DrawText("Press SPACE To Start", GetScreenWidth() / 4 + 70, GetScreenHeight() / 2 - 12.5, 30, WHITE);
}
