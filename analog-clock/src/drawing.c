#include <raylib.h>
#include <time.h>
#include <math.h>
#include "../include/params.h"
#include "../include/drawing.h"

void DrawClockFace(ClockFace *cf)
{
    DrawCircleV(screenCenter, cf->radius, cf->color);
    DrawCircleLinesV(screenCenter, cf->radius, cf->color);
}

void DrawClockMarks(ClockFace *cf)
{
    float startPos = cf->radius * 0.9f;
    float endPos = 0.0f;
    bool isMarkLong = false;
    for (int i = 0; i < 60; i++)
    {
        isMarkLong = (i == 0 || i % 5 == 0) ? true : false;
        endPos = (isMarkLong == true) ? cf->radius * 0.7f : cf->radius * 0.8f;
        float startVx = screenCenter.x + startPos * cosf(6.0f * i * PI / 180.0);
        float startVy = screenCenter.y + startPos * sinf(6.0f * i * PI / 180.0);
        Vector2 startV = {startVx, startVy};
        float endVx = screenCenter.x + endPos * cosf(6.0f * i * PI / 180.0);
        float endVy = screenCenter.x + endPos * sinf(6.0f * i * PI / 180.0);
        Vector2 endV = {endVx, endVy};
        DrawLineEx(startV, endV, 4.0f, DARKGRAY);
    }
}

void DrawClockHands(ClockHand *hch, ClockHand *mch, ClockHand *sch)
{
    time_t maintime = time(NULL);
    struct tm *time = localtime(&maintime);
    float hour = ((float)(time->tm_hour) > 12.0f) ? (float)(time->tm_hour) - 12.0f: (float)(time->tm_hour);
    hch->angle = ((hour * 30.0) - 90.0) * PI / 180.0;
    Vector2 hstartPos = screenCenter;
    Vector2 hendPos = {screenCenter.x + hch->length * cosf(hch->angle), screenCenter.y + hch->length * sinf(hch->angle)};
    DrawLineEx(hstartPos, hendPos, hch->thick, hch->color);

    float min = (float)(time->tm_min);
    mch->angle = ((min * 6.0) - 90.0) * PI / 180.0;
    Vector2 mstartPos = screenCenter;
    Vector2 mendPos = {screenCenter.x + mch->length * cosf(mch->angle), screenCenter.y + mch->length * sinf(mch->angle)};
    DrawLineEx(mstartPos, mendPos, mch->thick, mch->color);

    float sec = (float)(time->tm_sec);
    sch->angle = ((sec * 6.0) - 90.0) * PI / 180.0;
    Vector2 sstartPos = screenCenter;
    Vector2 sendPos = {screenCenter.x + sch->length * cosf(sch->angle), screenCenter.y + sch->length * sinf(sch->angle)};
    DrawLineEx(sstartPos, sendPos, sch->thick, sch->color);
}
