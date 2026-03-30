#include <raylib.h>
#include "../include/params.h"

const Vector2 screenSize = {700, 700};
const Vector2 screenCenter = {350, 350};

const int clockRadius = 300.0f;
const Color clockColor = LIGHTGRAY;

const int hourHandLength = 150.0f;
const int hourHandThick = 6.0f;
const int hourHandAngle = 0.0f;
const Color hourHandColor = BLACK;

const int minuteHandLength = 190.0f;
const int minuteHandThick = 4.0f;
const int minuteHandAngle = 0.0f;
const Color minuteHandColor = BLACK;

const int secondHandLength = 210.0f;
const int secondHandThick = 2.0f;
const int secondHandAngle = 0.0f;
const Color secondHandColor = RED;

ClockFace cf = {(int)clockRadius, clockColor, screenCenter};
ClockHand hourHand = {(int)hourHandLength, (int)hourHandThick, (int)hourHandAngle, hourHandColor};
ClockHand minuteHand = {(int)minuteHandLength, (int)minuteHandThick, (int)minuteHandAngle, minuteHandColor};
ClockHand secondHand = {(int)secondHandLength, (int)secondHandThick, (int)secondHandAngle, secondHandColor};

/*void InitClockFace(ClockFace *cl, int radius, Color color, Vector2 center)
{
    cl->radius = (int)radius;
    cl->color = color;
    cl->center = center;
}

//void InitClockHand(ClockHand *ch, int length, int thick, int angle, Color color)
{
    ch->length = (int)length;
    ch->thick = (int)thick;
    ch->color = color;
}
*/
