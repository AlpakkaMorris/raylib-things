#include <raylib.h>
#include <time.h>
#include <math.h>
#define RAYGUI_IMPLEMENTATION
#include "../include/raygui.h"
#include "../include/params.h"
#include "../include/drawing.h"
#include "../include/settings-window.h"

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

int main(void)
{
    ClockFace cf;
    InitClockFace(&cf, clockRadius, clockColor, screenCenter);

    ClockHand hourHand, minuteHand, secondHand;
    InitClockHand(&hourHand, hourHandLength, hourHandThick, hourHandAngle, hourHandColor);
    InitClockHand(&minuteHand, minuteHandLength, minuteHandThick, minuteHandAngle, minuteHandColor);
    InitClockHand(&secondHand, secondHandLength, secondHandThick, secondHandAngle, secondHandColor);

    InitWindow(screenSize.x, screenSize.y, "analog clock");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawClockFace(&cf);
            DrawClockMarks(&cf);
            DrawClockHands(&hourHand, &minuteHand, &secondHand);
            InitSettingsWindow();
        EndDrawing();

    }

    CloseWindow();

    return 0;
}
