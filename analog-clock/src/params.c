#include <raylib.h>
#include <stdio.h>
#include "../include/params.h"

const Vector2 screenSize = {700, 700};
const Vector2 screenCenter = {350, 350};

const int clockRadius = 300.0f;
const Color clockColor = LIGHTGRAY;

const int hourHandLength = 150.0f;
const int hourHandThick = 6.0f;
const float hourHandAngle = 0.0f;
const Color hourHandColor = BLACK;

const int minuteHandLength = 190.0f;
const int minuteHandThick = 4.0f;
const float minuteHandAngle = 0.0f;
const Color minuteHandColor = BLACK;

const int secondHandLength = 210.0f;
const int secondHandThick = 2.0f;
const float secondHandAngle = 0.0f;
const Color secondHandColor = RED;

ClockFace cf = {clockRadius, clockColor, screenCenter};
ClockHand hourHand = {(float)hourHandLength, (float)hourHandThick, hourHandAngle, hourHandColor};
ClockHand minuteHand = {(float)minuteHandLength, (float)minuteHandThick, minuteHandAngle, minuteHandColor};
ClockHand secondHand = {(float)secondHandLength, (float)secondHandThick, secondHandAngle, secondHandColor};

void UpdateClockParams(ClockFace *cf, ClockHand *hch, ClockHand *mch, ClockHand *sch)
{
    hch->length = cf->radius * 0.6f;
    mch->length = cf->radius * 0.7f;
    sch->length = cf->radius * 0.8f;
    printf("%f, %f, %f\n", hch->angle, mch->angle, sch->angle);
}
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
