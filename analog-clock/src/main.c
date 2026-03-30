#include <raylib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#define RAYGUI_IMPLEMENTATION
#include "../include/raygui.h"
#include "../include/params.h"
#include "../include/drawing.h"
#include "../include/settings-window.h"

int main(void)
{

    //InitClockFace(&cf, clockRadius, clockColor, screenCenter);


    //InitClockHand(&hourHand, hourHandLength, hourHandThick, hourHandAngle, hourHandColor);
    //InitClockHand(&minuteHand, minuteHandLength, minuteHandThick, minuteHandAngle, minuteHandColor);
    //InitClockHand(&secondHand, secondHandLength, secondHandThick, secondHandAngle, secondHandColor);

    bool isSettingsWindowOpened = false;


    InitWindow(screenSize.x, screenSize.y, "analog clock");
    //InitSettingsWindow();
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawClockFace(&cf);
            DrawClockMarks(&cf);
            DrawClockHands(&hourHand, &minuteHand, &secondHand);
            if (GuiButton((Rectangle){ 10, 10, 100, 100 }, "SHOW CONTENT AREA")) isSettingsWindowOpened = true;
            DrawSettingsWindow(&isSettingsWindowOpened);
        EndDrawing();

    }

    CloseWindow();

    return 0;
}
