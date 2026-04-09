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
bool editModeClock = false;
bool editModeHourHand = false;

int selectedClockColor = -1;
int selectedHourHandColor = -1;

const char* colors_list = "Red;Blue;Green;Gray";

void DrawSettingsWindow(bool *isSettingsWindowOpened)
{
      if (*isSettingsWindowOpened)
      {
        int result = GuiWindowBox(baseRec, "title");

        GuiScrollPanel(panelRec, NULL, panelContentRec, &panelScroll, &panelView);

        BeginScissorMode(panelView.x, panelView.y, panelView.width, panelView.height);

          DrawSettingsSelector("Hour Hand Color", 3, colors_list, &hourHand.color, &selectedHourHandColor, &editModeHourHand);

          DrawSettingsSelector("Clock Color", 2, colors_list, &cf.color,  &selectedClockColor, &editModeClock);
        DrawSettingsLabel("Clock Radius", 1, &cf.radius);
        EndScissorMode();
      if (result > 0) *isSettingsWindowOpened = false;
      }
}

void DrawSettingsLabel(const char* settingName, int position, int* settingValue)
{
  GuiLabel((Rectangle){panelContentRec.x + 30 + panelScroll.x, panelContentRec.y + (30 * position) + panelScroll.y, 150, 24}, settingName);
  GuiValueBox((Rectangle){panelContentRec.x + 140 + panelScroll.x, panelContentRec.y + (30 * position) + panelScroll.y, 50, 24}, "", settingValue, 0, 1000, 1);
}

void DrawSettingsSelector(const char* settingName, int position, const char* options, Color *settingValue, int *selectedColor, bool* editMode)
{
  GuiLabel((Rectangle){panelContentRec.x + 30 + panelScroll.x, panelContentRec.y + (30 * position) + panelScroll.y, 150, 24}, settingName);
  if(GuiDropdownBox((Rectangle){panelContentRec.x + 140 + panelScroll.x, panelContentRec.y + (30 * position) + panelScroll.y, 50, 24}, options, selectedColor, *editMode)) *editMode = !*editMode;
  SelectColor(selectedColor, settingValue);
}

void SelectColor(int *selected, Color *color)
{
  switch(*selected)
  {
    case 0: *color = RED; break;
    case 1: *color = BLUE; break;
    case 2: *color = GREEN; break;
    case 3: *color = LIGHTGRAY; break;
    default: break;
  }
}
