#include <raylib.h>
#include "../include/drawing.h"

Vector2 startPoint = {25,25};
Vector2 endPoint = {25,25};
int distance = 50;

void DrawMainGoBoard(int size)
{
    for (int i = 0; i < size; i++)
    {
        DrawLineV((Vector2){startPoint.x, startPoint.y + (i * distance)},
                  (Vector2){startPoint.x + 900, startPoint.y + (i * distance)},
                   BLACK);
        DrawLineV((Vector2){startPoint.x + (i * distance), startPoint.y},
                  (Vector2){startPoint.x + (i * distance), startPoint.y + 900},
                   BLACK);

    }
}
