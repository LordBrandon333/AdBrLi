#include "raylib.h"
#include "global_variable.h"

int localtimeCounter = timeCounter;

void screen_game(){
    if (localtimeCounter == 0){
        localtimeCounter = 360;
    }
    DrawText(TextFormat("Remaining Time: %i", localtimeCounter / 60), 10, 10, 30, LIGHTGRAY);
    localtimeCounter--;
}