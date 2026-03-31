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
    bool isSettingsWindowOpened = false;

    InitWindow(screenSize.x, screenSize.y, "analog clock");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawClockFace(&cf);
            DrawClockMarks(&cf);
            DrawClockHands(&hourHand, &minuteHand, &secondHand);
            if (GuiButton((Rectangle){ 10, 10, 100, 100 }, "SETTINGS")) isSettingsWindowOpened = true;
            DrawSettingsWindow(&isSettingsWindowOpened);
        EndDrawing();

    }

    CloseWindow();

    return 0;
}
