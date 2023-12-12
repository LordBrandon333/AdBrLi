#include <cstdlib> //First Version
#include <iostream>

#include "raylib.h"

#include "config.h"
#include "screen_menu.h"
#include "screen_game.h"
#include "screen_gameover.h"

enum states {menu, game, gameover};

enum states globalgamestate = menu;

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
    Texture2D myTexture = LoadTexture("assets/graphics/testimage.png");

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Updates that are made by frame are coded here
        // ...
        // ...
        if (IsKeyReleased(KEY_KP_0)){
            globalgamestate = menu;
        }
        if (IsKeyReleased(KEY_KP_1)){
            globalgamestate = game;
        }
        if (IsKeyReleased(KEY_KP_2)){
            globalgamestate = gameover;
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
