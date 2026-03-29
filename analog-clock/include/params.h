#ifndef PARAMS_H
#define PARAMS_H

extern Vector2 screenSize;
extern Vector2 screenCenter;

extern float clockRadius;
extern Color clockColor;

extern float hourHandLength;
extern float hourHandThick;
extern float hourHandAngle;
extern Color hourHandColor;

extern float minuteHandLength;
extern float minuteHandThick;
extern float minuteHandAngle;
extern Color minuteHandColor;

extern float secondHandLength;
extern float secondHandThick;
extern float secondHandAngle;
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

void InitClockFace(ClockFace *cl, float radius, Color color, Vector2 center);
void InitClockHand(ClockHand *ch, float length, float thick, float angle, Color color);

#endif
