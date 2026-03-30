#include <raylib.h>

#include <stdio.h>
#include "../include/params.h"
#include "../include/raygui.h"
#include "../include/settings-window.h"

Rectangle panelRec = { 50, 50, 300, 300 };
Rectangle panelContentRec = {26, 26, 440, 440 };
Rectangle panelView = { 0 };
Vector2 panelScroll = { 99, -20 };
int baseOffset = 50;

bool showContentArea = true;

void DrawSettingsWindow(bool *isSettingsWindowOpened)
{
      if (*isSettingsWindowOpened)
      {
      int result = GuiWindowBox(panelContentRec, "title");
        //ClearBackground(RAYWHITE);
      int temp = clockRadius;

       DrawRectangle(panelRec.x + panelScroll.x, panelRec.y + panelScroll.y, panelContentRec.width, panelContentRec.height, Fade(RED, 0.1));


        DrawText(TextFormat("[%f, %f]", panelScroll.x, panelScroll.y), 4, 4, 20, RED);

        GuiScrollPanel(panelRec, NULL, panelContentRec, &panelScroll, &panelView);

        BeginScissorMode(panelView.x, panelView.y, panelView.width, panelView.height);
          //GuiGrid((Rectangle){panelRec.x + panelScroll.x, panelRec.y + panelScroll.y,   panelContentRec.width, panelContentRec.height}, NULL, 16, 3, NULL);
          //int res = GuiButton((Rectangle){baseOffset + panelScroll.x, baseOffset + panelScroll.y, 100, 50}, "test");
          DrawSettingsLabel("testttt", 1, &temp);
          //DrawSettingsLabel("size", 2, &)baseOffset);
        EndScissorMode();
      if (result > 0) *isSettingsWindowOpened = false;
      }
}

void DrawSettingsLabel(const char* settingName, int position, int* settingValue)
{
  GuiLabel((Rectangle){panelContentRec.x + 30 + panelScroll.x, panelContentRec.y + (30 * position) + panelScroll.y, 100, 24}, settingName);
  //GuiButton((Rectangle){panelContentRec.x + 140 + panelScroll.x, panelContentRec.y + (30 * position) + panelScroll.y, 50, 24}, "tset button");
  GuiValueBox((Rectangle){panelContentRec.x + 140 + panelScroll.x, panelContentRec.y + (30 * position) + panelScroll.y, 50, 24}, "test", settingValue, 0, 1000, 1);
}

