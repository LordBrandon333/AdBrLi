#include <cstdlib> //First Version
#include <iostream>
#include "raylib.h"
#include "config.h"
#include "global_variable.h"
#include "screen_menu.h"
#include "screen_game.h"
#include "screen_gameover.h"

enum states {menu, game, gameover};

enum states globalgamestate = menu;

int frameCounter = 0;

struct clickThis{
    Vector2 Pos;
    int speed;
    int raduis;
};


int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);
#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here
    // ...
    // ...
    clickThis fallingThingies[6]{};
    for (int i = 0; i < 6; i++){
        fallingThingies[i].Pos.x = GetRandomValue(0, 600);
        fallingThingies[i].Pos.y = 10;
        fallingThingies[i].speed = 5;
        fallingThingies[i].raduis = 10;
    }

    Texture2D sprite = LoadTexture("assets/graphics/blue_creature_thing-export.png");

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        if (frameCounter == 360)
        {
            globalgamestate = gameover;
        }
       if (IsKeyReleased(KEY_ENTER) & globalgamestate == gameover){
           frameCounter = 0;
           globalgamestate = menu;
        }
        if (IsKeyReleased(KEY_SPACE) & globalgamestate == menu){
            globalgamestate = game;
        }
       /* if (IsKeyReleased(KEY_SPACE)){
            globalgamestate = gameover;
        } */

       // falling Thingies falling down
        for (int i = 0; i < 6; ++i) {
            fallingThingies[i].Pos.y += fallingThingies[i].speed;
        }


        BeginDrawing();
            // You can draw on the screen between BeginDrawing() and EndDrawing()
            // ...
            // ...
            ClearBackground(WHITE);

        switch (globalgamestate) {
            case menu:
                screen_menu();
                break;
            case game:
                screen_game();
                frameCounter++;
                DrawTexture(sprite, GetScreenWidth() / 2, GetScreenHeight() / 2, WHITE);
                for (int i = 0; i < 6; ++i) {
                    DrawCircle(fallingThingies[i].Pos.x,fallingThingies[i].Pos.y,fallingThingies[i].raduis,RED);
                }
                break;
            case gameover:
                screen_gameover();
                break;
        }


        EndDrawing();
    } // Main game loop end

    // De-initialization here
    // ...
    // ...
    //UnloadTexture(myTexture);

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
