#include <raylib.h>
#include "../include/raygui.h"
#include "../include/settings-window.h"

Vector2 settingsScreenSize = {500.0f, 500.0f};
Vector2 rectStart = {100.0f, 100.0f};
Vector2 rectSize = {100.0f, 100.0f};
bool showMessageBox = false;
Vector2 scroll = {0, 0};
Rectangle view = {100,100,300,300};
void InitSettingsWindow()
{
    if (GuiButton((Rectangle){ 24, 24, 120, 30 }, "#191#Show Message")) showMessageBox = true;
        if (showMessageBox)
        {
            int result = GuiMessageBox((Rectangle){ 85, 70, 250, 100 },
            "#191#Message Box", "Hi! This is a message!", "Nice;Cool");
            int result2 = GuiScrollPanel((Rectangle){100,100,300,300}, "test text", (Rectangle){10,10,2800,2800}, &scroll, &view);
            if (result >= 0) showMessageBox = false;
        }
}
