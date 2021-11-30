/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

typedef enum GameScreen{LOGO = 0, TITLE, GAMEPLAY, ENDING} GameScreen;

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    int framecounter = 0;

    GameScreen currentScreen = LOGO;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        switch (currentScreen)
        {
            case LOGO:
            {
                framecounter++;
                if (framecounter >= 120) {
                    currentScreen = TITLE;
                }
            } break;
            case TITLE:
            {
                if (IsKeyPressed(KEY_ENTER)) {
                    currentScreen = GAMEPLAY;
                }
            } break;
            case GAMEPLAY:
            {
                if (IsKeyPressed(KEY_SPACE)) {
                    currentScreen = ENDING;
                }
            } break;
            case ENDING:
            {
                if (IsKeyPressed(KEY_ENTER)) {
                    currentScreen = LOGO;
                    framecounter = 0;
                }
            } break;
            default:
            { break; }
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);
        switch (currentScreen)
        {
            case LOGO:
            {
                DrawText("COOL LOGO HERE", 20, 20, 42, LIGHTGRAY);
                DrawText("Wait for two seconds", 40, 40, 42, LIGHTGRAY);
            } break;
            case TITLE:
            {
                DrawRectangle(0, 0, screenWidth, screenHeight, LIME);
                DrawText("COOL TITLE HERE", 20, 20, 42, DARKGREEN);
                DrawText("PRESS ENTER", 40, 40, 42, DARKGREEN);

            } break;
            case GAMEPLAY:
            {
                DrawRectangle(0, 0, screenWidth, screenHeight, MAGENTA);
                DrawText("COOL GAME HERE", 20, 20, 42, MAROON);
                DrawText("press spacebar", 40, 40, 42, MAROON);

            } break;
            case ENDING:
            {
                DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                DrawText("CONGRATULATIONS", 20, 20, 42, DARKBLUE);
                DrawText("press enter to return to title", 40, 40, 42, DARKBLUE);

            } break;
            default:
                break;
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
