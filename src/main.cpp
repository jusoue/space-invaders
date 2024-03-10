#include "raylib.h"

int main(int argc, char** argv)
{
    InitWindow(600, 800, "Space Invaders");
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}