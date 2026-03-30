#include <raylib.h>
#include "../include/params.h"

Vector2 screenSize = {700, 700};
Vector2 screenCenter = {350, 350};

float clockRadius = 300.0f;
Color clockColor = LIGHTGRAY;

float hourHandLength = 150.0f;
float hourHandThick = 6.0f;
float hourHandAngle = 0.0f;
Color hourHandColor = BLACK;

float minuteHandLength = 190.0f;
float minuteHandThick = 4.0f;
float minuteHandAngle = 0.0f;
Color minuteHandColor = BLACK;

float secondHandLength = 210.0f;
float secondHandThick = 2.0f;
float secondHandAngle = 0.0f;
Color secondHandColor = RED;

void InitClockFace(ClockFace *cl, float radius, Color color, Vector2 center)
{
    cl->radius = radius;
    cl->color = color;
    cl->center = center;
}

void InitClockHand(ClockHand *ch, float length, float thick, float angle, Color color)
{
    ch->length = length;
    ch->thick = thick;
    ch->color = color;
}
