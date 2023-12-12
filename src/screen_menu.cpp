#include "raylib.h"

void screen_menu(){
    DrawCircle(GetScreenWidth() / 2 , GetScreenHeight() / 2, 150, RED);
    DrawText("Press SPACE", GetScreenWidth() / 3 + 55, GetScreenHeight() / 2 - 35, 30, WHITE);
    DrawText("to start", GetScreenWidth() / 3 + 90, GetScreenHeight() / 2 + 5, 30, WHITE);
    DrawText("CoolesGame24", GetScreenWidth() / 3 - 20, GetScreenHeight() / 20, 50,GREEN);
}
