#include <raylib.h>
#include <stdio.h>
#include "../include/params.h"
#include "../include/raygui.h"
#include "../include/settings-window.h"

Rectangle settingsWindowGuiWindowBoxRect = { 48, 48, 336, 220 };
Rectangle settingsWindowGuiScrollPanelRect= {48, 72, 336, 220 };
Rectangle settingsWindowGuiScrollPanelView = { 0 };
Vector2 settingsWindowGuiScrollPanelScroll = { 99, 20 };
int settingsWindowElementBaseOffset = 50;

void DrawSettingsWindow(bool *isSettingsWindowOpened)
  {
  if (*isSettingsWindowOpened)
  {
    int result = GuiWindowBox(settingsWindowGuiWindowBoxRect, "title");

    GuiScrollPanel(settingsWindowGuiScrollPanelRect, NULL, settingsWindowGuiWindowBoxRect, &settingsWindowGuiScrollPanelScroll, &settingsWindowGuiScrollPanelView);

    BeginScissorMode(settingsWindowGuiScrollPanelView.x, settingsWindowGuiScrollPanelView.y, settingsWindowGuiScrollPanelView.width, settingsWindowGuiScrollPanelView.height);
      //GuiGrid((Rectangle){settingsWindowGuiWindowBoxRect.x + settingsWindowGuiScrollPanelScroll.x, settingsWindowGuiWindowBoxRect.y + settingsWindowGuiScrollPanelScroll.y,   settingsWindowGuiScrollPanelRect.width, settingsWindowGuiScrollPanelRect.height}, NULL, 16, 3, NULL);
      //int res = GuiButton((Rectangle){settingsWindowElementBaseOffset + settingsWindowGuiScrollPanelScroll.x, settingsWindowElementBaseOffset + settingsWindowGuiScrollPanelScroll.y, 100, 50}, "test");
      DrawSettingsLabel("Clock Radius", 1, &cf.radius);
      DrawSettingsLabel("Clock Radius", 2, &cf.radius);
      DrawSettingsLabel("Clock Radius", 3, &cf.radius);
      DrawSettingsLabel("Clock Radius", 4, &cf.radius);
      DrawSettingsLabel("Clock Radius", 5, &cf.radius);
      DrawSettingsLabel("Clock Radius", 6, &cf.radius);
      DrawSettingsLabel("Clock Radius", 7, &cf.radius);
      DrawSettingsLabel("Clock Radius", 8, &cf.radius);
      DrawSettingsLabel("Clock Radius", 9, &cf.radius);
      DrawSettingsLabel("Clock Radius", 10, &cf.radius);
      //DrawSettingsLabel("size", 2, &)settingsWindowElementBaseOffset);
    EndScissorMode();
    if (result > 0) *isSettingsWindowOpened = false;
      }
}

void DrawSettingsLabel(const char* settingName, int position, int* settingValue)
{
  GuiLabel((Rectangle){settingsWindowGuiWindowBoxRect.x + 30 + settingsWindowGuiScrollPanelScroll.x, settingsWindowGuiWindowBoxRect.y + (30 * position) + settingsWindowGuiScrollPanelScroll.y, 100, 24}, settingName);
  //GuiButton((Rectangle){settingsWindowGuiScrollPanelRect.x + 140 + settingsWindowGuiScrollPanelScroll.x, settingsWindowGuiScrollPanelRect.y + (30 * position) + settingsWindowGuiScrollPanelScroll.y, 50, 24}, "tset button");
  GuiValueBox((Rectangle){settingsWindowGuiWindowBoxRect.x + 140 + settingsWindowGuiScrollPanelScroll.x, settingsWindowGuiWindowBoxRect.y + (30 * position) + settingsWindowGuiScrollPanelScroll.y, 50, 24}, "test", settingValue, 0, 1000, 1);
}

