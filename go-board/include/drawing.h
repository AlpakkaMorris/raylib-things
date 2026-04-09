#ifndef DRAWING_H
#define DRAWING_H

extern Vector2 startPoint;
extern Vector2 endPoint;
extern int distance;
extern int stoneRadius;
void DrawMainGoBoard(int size);
void DrawGoStone(Vector2 coords, Color color);
#endif
