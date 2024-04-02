#include "raylib.h"

#include "space_invaders.h"

int main(int argc, char** argv)
{
    InitWindow(600, 800, "Space Invaders");

    SpaceInvaders game{};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        game.update();
        game.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}