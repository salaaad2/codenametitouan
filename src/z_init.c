/*******************************************************************************************
*
*   raylib [core] examples - basic screen manager
*
*   This example illustrates a very simple screen manager based on a states machines
*
*   This test has been created using raylib 1.1 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2021 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

/*
** z_init.c --> main
** z_hdr.c --> function definitions
** screens.c --> gameplay & title screens
 */

#include "z_hdr.h"

//------------------------------------------------------------------------------------------
// Main entry point
//------------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    t_geo geo;

    InitWindow(GAME_WIDTH, GAME_HEIGHT, "codename titouan v0.0.1");

    gameState currentScreen = LOADING;

    /* TODO: Initialize all required variables and load all required data here! */

    int framesCounter = 0;          // Useful to count frames

    Camera camera = { 0 };
    camera.position = (Vector3){ 4.0f, 2.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    /* Generates some random columns */
    for (int i = 0; i < MAX_COLUMNS; i++)
    {
        geo.heights[i] = (float)GetRandomValue(1, 12);
        geo.positions[i] = (Vector3){ (float)GetRandomValue(-15, 15), geo.heights[i]/2.0f, (float)GetRandomValue(-15, 15) };
        geo.colors[i] = (Color){ GetRandomValue(20, 255), GetRandomValue(10, 55), 30, 255 };
    }

    SetCameraMode(camera, CAMERA_FIRST_PERSON); // Set a first person camera mode

    SetTargetFPS(60);               // Set desired framerate (frames-per-second)
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        switch(currentScreen)
        {
            case LOADING:
            {
                // TODO: Update LOGO screen variables here!

                framesCounter++;    // Count frames

                // Wait for 2 seconds (120 frames) before jumping to TITLE screen
                if (framesCounter > 120)
                {
                    currentScreen = TITLE;
                }
            } break;
            case TITLE:
            {
                // TODO: Update TITLE screen variables here!

                // Press enter to change to GAMEPLAY screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = GAMEPLAY;
                }
            } break;
            case GAMEPLAY:
            {
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = ENDING;
                }
            } break;
            case ENDING:
            {
                // TODO: Update ENDING screen variables here!

                // Press enter to return to TITLE screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = TITLE;
                }
            } break;
            default: break;
        }
        //----------------------------------------------------------------------------------

        UpdateCamera(&camera);
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            switch(currentScreen)
            {
                case LOADING:
                {
                    // TODO: Draw LOGO screen here!
                    z_title();

                } break;
                case TITLE:
                {
                    z_title();
                    /* TODO: Draw TITLE screen here! */
                    DrawRectangle(0, 0, GAME_WIDTH, GAME_HEIGHT, GREEN);
                    DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
                    DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);
                } break;
                case GAMEPLAY:
                {
                printf("Im stuck\n");
                    z_gameplay(&camera, &geo);
                } break;
                case ENDING:
                {
                    /* TODO: make a cool ending */
                    DrawRectangle(0, 0, GAME_WIDTH, GAME_HEIGHT, BLUE);
                    DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
                    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

                } break;
                default: break;
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // TODO: Unload all loaded data (textures, fonts, audio) here!

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
