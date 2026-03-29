#include <raylib.h>
#include "../include/params.h"

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
