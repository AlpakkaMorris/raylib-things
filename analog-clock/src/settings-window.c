#include <raylib.h>
#include <stdio.h>
#include "../include/params.h"
#include "../include/raygui.h"
#include "../include/settings-window.h"

const int windowWidth = 300;
const int windowHeight = 300;
const int baseCoord = 50;
const int windowTitleOffset = 24;

Rectangle baseRec = { baseCoord, baseCoord - 24, windowWidth, windowHeight - 100 };
Rectangle panelRec = { baseCoord, baseCoord, windowWidth, windowHeight - 100 };
Rectangle panelContentRec = { baseCoord,
                              baseCoord - windowTitleOffset,
                              windowWidth, windowHeight};
Rectangle panelView = { 0 };
Vector2 panelScroll = { 0, 0 };
int baseOffset = 50;

bool showContentArea = true;

void DrawSettingsWindow(bool *isSettingsWindowOpened)
{
      if (*isSettingsWindowOpened)
      {
      int result = GuiWindowBox(baseRec, "title");

      DrawRectangle(panelRec.x + panelScroll.x, panelRec.y + panelScroll.y, panelContentRec.width, panelContentRec.height, Fade(RED, 0.1));


        DrawText(TextFormat("[%f, %f]", panelScroll.x, panelScroll.y), 4, 4, 20, RED);

        GuiScrollPanel(panelRec, NULL, panelContentRec, &panelScroll, &panelView);

        BeginScissorMode(panelView.x, panelView.y, panelView.width, panelView.height);
          DrawSettingsLabel("Clock Radius", 1, &cf.radius);
          DrawSettingsLabel("Clock Radius", 2, &cf.radius);
          DrawSettingsLabel("Clock Radius", 3, &cf.radius);
          DrawSettingsLabel("Clock Radius", 4, &cf.radius);
        EndScissorMode();
      if (result > 0) *isSettingsWindowOpened = false;
      }
}

void DrawSettingsLabel(const char* settingName, int position, int* settingValue)
{
  GuiLabel((Rectangle){panelContentRec.x + 30 + panelScroll.x, panelContentRec.y + (30 * position) + panelScroll.y, 100, 24}, settingName);
  GuiValueBox((Rectangle){panelContentRec.x + 140 + panelScroll.x, panelContentRec.y + (30 * position) + panelScroll.y, 50, 24}, "test", settingValue, 0, 1000, 1);
}

