#include <raylib.h>
#include "../include/drawing.h"

Vector2 startPoint = {25,25};
Vector2 endPoint = {25,25};
int distance = 50;
int stoneRadius = 20;

void DrawMainGoBoard(int size)
{
    for (int i = 0; i < size; i++)
    {
        DrawLineV((Vector2){startPoint.x, startPoint.y + (i * distance)},
                  (Vector2){startPoint.x + (distance * (size - 1)), startPoint.y + (i * distance)},
                   BLACK);
        DrawLineV((Vector2){startPoint.x + (i * distance), startPoint.y},
                  (Vector2){startPoint.x + (i * distance), startPoint.y + (distance * (size - 1))},
                   BLACK);

    }
}
void DrawGoStone(Vector2 coords, Color color)
{
    DrawCircleV(coords, stoneRadius, color);
}
