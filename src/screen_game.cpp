#include "raylib.h"

int timeCounter = 3600;

void screen_game(){
    DrawText(TextFormat("Remaining Time: %i", timeCounter / 60), 10, 10, 30, LIGHTGRAY);
    timeCounter--;
}