#ifndef PARAMS_H
#define PARAMS_H

const extern Vector2 screenSize;
const extern Vector2 screenCenter;

const extern int clockRadius;
const extern Color clockColor;

const extern int hourHandLength;
const extern int hourHandThick;
const extern int hourHandAngle;
const extern Color hourHandColor;

const extern int minuteHandLength;
const extern int minuteHandThick;
const extern int minuteHandAngle;
const extern Color minuteHandColor;

const extern int secondHandLength;
const extern int secondHandThick;
const extern int secondHandAngle;
const extern Color secondHandColor;

typedef struct
{
    int radius;
    Color color;
    Vector2 center;
} ClockFace;

typedef struct
{
    float length;
    float thick;
    float angle;
    Color color;
} ClockHand;

extern ClockFace cf;
extern ClockHand hourHand, minuteHand, secondHand;

#endif
