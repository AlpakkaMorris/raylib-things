#include <raylib.h>
#include "../include/drawing.h"

int main()
{
    InitWindow(1000, 1000, "Go Board");
    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        ClearBackground(RAYWHITE);
        BeginDrawing();
            DrawMainGoBoard(19);
            if (IsMouseButtonPressed(1))
            {
                Vector2 pos = GetMousePosition();
                DrawGoStone(pos, BLACK);
            }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
