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


int main() {

    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);
#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here

    Vector2 enemies[50];
    Texture2D texture;

    texture = LoadTexture("assets/graphics/testimage.png");

    for (int i = 0; i < 50; i++)
    {
        enemies[i].x = (float) GetRandomValue(0, GetScreenWidth());
        enemies[i].y = (float) GetRandomValue(0, GetScreenHeight());
    }
    // ...
    //Texture2D myTexture = LoadTexture("assets/graphics/testimage.png");

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        if (frameCounter == 360)
        {
            globalgamestate = gameover;
        }
       if (IsKeyReleased(KEY_ENTER) & globalgamestate == gameover){
           frameCounter = 0;
           //timeCounter = 360; hinzufügen
           globalgamestate = menu;
        }
        if (IsKeyReleased(KEY_SPACE) & globalgamestate == menu){
            globalgamestate = game;
        }
       /* if (IsKeyReleased(KEY_SPACE)){
            globalgamestate = gameover;
        } */
        BeginDrawing();
            // You can draw on the screen between BeginDrawing() and EndDrawing()
            // ...
            // ...
            ClearBackground(WHITE);
        for(int i = 0; i < 50; i++)
        {
            DrawTexture(texture, (int) enemies[i].x, (int) enemies[i].y, WHITE);
        }


        switch (globalgamestate) {
            case menu:
                screen_menu();
                break;
            case game:
                screen_game();
                frameCounter++;
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
    UnloadTexture(texture);

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
