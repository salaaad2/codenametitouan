#include "z_hdr.h"

int
z_title( void ) {
    DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
    DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);
    return (0);
}

int
z_gameplay(Camera camera, t_geo * geo) {
    ClearBackground(RAYWHITE);

    BeginMode3D(camera);

    DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, LIGHTGRAY); // Draw ground
    DrawCube((Vector3){ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);     // Draw a blue wall
    DrawCube((Vector3){ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME);      // Draw a green wall
    DrawCube((Vector3){ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD);      // Draw a yellow wall

    // Draw some cubes around
    for (int i = 0; i < MAX_COLUMNS; i++)
    {
        DrawCube(geo->positions[i], 2.0f, geo->heights[i], 2.0f, geo->colors[i]);
        DrawCubeWires(geo->positions[i], 2.0f, geo->heights[i], 2.0f, MAROON);
    }

    EndMode3D();

    DrawRectangle( 10, 10, 220, 70, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines( 10, 10, 220, 70, BLUE);

    DrawText("First person camera default controls:", 20, 20, 10, BLACK);
    DrawText("- Move with keys: W, A, S, D", 40, 40, 10, DARKGRAY);
    DrawText("- Mouse move to look around", 40, 60, 10, DARKGRAY);

    return (0);
}
