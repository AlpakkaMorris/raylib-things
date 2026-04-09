#ifndef SETTINGS_WINDOW_H
#define SETTINGS_WINDOW_H

void DrawSettingsWindow(bool* isSettingsWindowOpened);
void DrawSettingsLabel(const char* settingName, int position, int* settingValue);
void DrawSettingsSelector(const char* settingName, int position, const char* options, Color *settingValue, int *selectedColor, bool *editMode);
void SelectColor(int *selected, Color *color);
#endif
