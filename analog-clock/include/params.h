#ifndef PARAMS_H
#define PARAMS_H

extern Vector2 screenSize;
extern Vector2 screenCenter;

extern int clockRadius;
extern Color clockColor;

extern int hourHandLength;
extern int hourHandThick;
extern int hourHandAngle;
extern Color hourHandColor;

extern int minuteHandLength;
extern int minuteHandThick;
extern int minuteHandAngle;
extern Color minuteHandColor;

extern int secondHandLength;
extern int secondHandThick;
extern int secondHandAngle;
extern Color secondHandColor;

typedef struct
{
    float radius;
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

void InitClockFace(ClockFace *cl, int radius, Color color, Vector2 center);
void InitClockHand(ClockHand *ch, int length, int thick, int angle, Color color);

#endif
