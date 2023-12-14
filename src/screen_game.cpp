#include "raylib.h"
#include "global_variable.h"

int timeCounter = 360;

void screen_game(){
    if (timeCounter == 0){
        timeCounter = 360;
    }
    DrawText(TextFormat("Remaining Time: %i", timeCounter / 60), 10, 10, 30, LIGHTGRAY);
    timeCounter--;


}