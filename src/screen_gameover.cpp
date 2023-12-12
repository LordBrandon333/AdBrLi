#include "raylib.h"

void screen_gameover(){
    DrawText("Game Over nob\n", 250, GetScreenHeight() / 2.0f - 60, 60, RED);
    DrawText("Press ENTER to continue", 335, GetScreenHeight() / 2.0f - 5, 20, BLACK);
}

