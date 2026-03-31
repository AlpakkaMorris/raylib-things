#include <raylib.h>
#include "../include/params.h"

const Vector2 screenSize = {700, 700};
const Vector2 screenCenter = {350, 350};

const int clockRadius = 300;
const Color clockColor = LIGHTGRAY;

const int hourHandLength = 150;
const int hourHandThick = 6;
const int hourHandAngle = 0;
const Color hourHandColor = BLACK;

const int minuteHandLength = 190;
const int minuteHandThick = 4;
const int minuteHandAngle = 0;
const Color minuteHandColor = BLACK;

const int secondHandLength = 210;
const int secondHandThick = 2;
const int secondHandAngle = 0;
const Color secondHandColor = RED;

ClockFace cf = {clockRadius, clockColor, screenCenter};
ClockHand hourHand = {(float)hourHandLength, (float)hourHandThick, (float)hourHandAngle, hourHandColor};
ClockHand minuteHand = {(float)minuteHandLength, (float)minuteHandThick, (float)minuteHandAngle, minuteHandColor};
ClockHand secondHand = {(float)secondHandLength, (float)secondHandThick, (float)secondHandAngle, secondHandColor};

void UpdateSettingsValues(ClockFace *cf, ClockHand *hch, ClockHand *mch, ClockHand *sch)
{
    hch->length = (float)cf->radius * 0.6f;
    mch->length = (float)cf->radius * 0.7f;
    sch->length = (float)cf->radius * 0.8f;
}
