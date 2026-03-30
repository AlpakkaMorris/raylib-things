#include <raylib.h>
#include "../include/params.h"

Vector2 screenSize = {700, 700};
Vector2 screenCenter = {350, 350};

int clockRadius = 300.0f;
Color clockColor = LIGHTGRAY;

int hourHandLength = 150.0f;
int hourHandThick = 6.0f;
int hourHandAngle = 0.0f;
Color hourHandColor = BLACK;

int minuteHandLength = 190.0f;
int minuteHandThick = 4.0f;
int minuteHandAngle = 0.0f;
Color minuteHandColor = BLACK;

int secondHandLength = 210.0f;
int secondHandThick = 2.0f;
int secondHandAngle = 0.0f;
Color secondHandColor = RED;

void InitClockFace(ClockFace *cl, int radius, Color color, Vector2 center)
{
    cl->radius = (float)radius;
    cl->color = color;
    cl->center = center;
}

void InitClockHand(ClockHand *ch, int length, int thick, int angle, Color color)
{
    ch->length = (float)length;
    ch->thick = (float)thick;
    ch->color = color;
}
