#include <raylib.h>
#include <stdio.h>
#include "../include/params.h"
#include "../include/raygui.h"
#include "../include/settings-window.h"

Rectangle settingsWindowMainRect = { 50, 50, 300, 300 };
Rectangle settingsWindowContentRect = {26, 26, 440, 440 };
Rectangle settingsWindowView = { 0 };
Vector2 settingsWindowScroll = { 99, -20 };
int settingsWindowElementBaseOffset = 50;

void DrawSettingsWindow(bool *isSettingsWindowOpened)
  {
  if (*isSettingsWindowOpened)
  {
    int result = GuiWindowBox(settingsWindowContentRect, "title");

    GuiScrollPanel(settingsWindowMainRect, NULL, settingsWindowContentRect, &settingsWindowScroll, &settingsWindowView);

    BeginScissorMode(settingsWindowView.x, settingsWindowView.y, settingsWindowView.width, settingsWindowView.height);
      //GuiGrid((Rectangle){settingsWindowMainRect.x + settingsWindowScroll.x, settingsWindowMainRect.y + settingsWindowScroll.y,   settingsWindowContentRect.width, settingsWindowContentRect.height}, NULL, 16, 3, NULL);
      //int res = GuiButton((Rectangle){settingsWindowElementBaseOffset + settingsWindowScroll.x, settingsWindowElementBaseOffset + settingsWindowScroll.y, 100, 50}, "test");
      DrawSettingsLabel("Clock Radius", 1, &hourHand.length);
      //DrawSettingsLabel("size", 2, &)settingsWindowElementBaseOffset);
    EndScissorMode();
    if (result > 0) *isSettingsWindowOpened = false;
      }
}

void DrawSettingsLabel(const char* settingName, int position, int* settingValue)
{
  GuiLabel((Rectangle){settingsWindowContentRect.x + 30 + settingsWindowScroll.x, settingsWindowContentRect.y + (30 * position) + settingsWindowScroll.y, 100, 24}, settingName);
  //GuiButton((Rectangle){settingsWindowContentRect.x + 140 + settingsWindowScroll.x, settingsWindowContentRect.y + (30 * position) + settingsWindowScroll.y, 50, 24}, "tset button");
  GuiValueBox((Rectangle){settingsWindowContentRect.x + 140 + settingsWindowScroll.x, settingsWindowContentRect.y + (30 * position) + settingsWindowScroll.y, 50, 24}, "test", settingValue, 0, 1000, 1);
}

