#include <cstdlib> //First Version
#include <iostream>

#include "raylib.h"

#include "config.h"
#include "screen_menu.h"
#include "screen_game.h"
#include "screen_gameover.h"

enum states {menu, game, gameover};

enum states globalgamestate = menu;

int frameCounter = 0;

int main() {

    /*Vector2 v1 = {0.0, 0.0};
    Vector2 v2 = {0.0, 0.0};
    Vector2 v3 = {0.0, 0.0};
    Vector2 v4 = {0.0, 0.0};

    v1.x = 3.2;
    v1.y = 10.5; */

    //Code für z.B. init-Funtkion state_game_init()

    Vector2 enemies[50];
    Texture2D texture;

    texture = LoadTexture("assets/enemy.png");

    for (int i = 0; i < 50; i++)
    {
        enemies[i].x = (float) GetRandomValue(0, GetScreenWidth());
        enemies[i].y = (float) GetRandomValue(0, GetScreenHeight());
    }

    //In die Draw Methode state_game_draw()

    for(int i = 0; i < 50; i++)
    {
        DrawTexture(texture, (int) enemies[i].x, (int) enemies[i].y, WHITE);
    }








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
    Texture2D myTexture = LoadTexture("assets/graphics/testimage.png");

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        if (frameCounter == 300)
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
    UnloadTexture(myTexture);

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
