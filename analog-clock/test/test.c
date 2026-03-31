#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include "../include/raygui.h"

#define MAX_ITEMS 30
#define ITEM_HEIGHT 30

typedef struct {
    char name[50];
    bool selected;
} ScrollItem;

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "raygui - Scroll Panel Example");
    SetTargetFPS(60);
    
    GuiLoadStyleDefault();
    
    // Window state
    Rectangle window_bounds = { 100, 100, 450, 500 };
    bool drag_window = false;
    Vector2 drag_offset = { 0, 0 };
    
    // Scroll panel state
    Rectangle panel_bounds = { 0, 0, 0, 0 };
    Vector2 panel_scroll = { 0, 0 };
    Rectangle view_bounds = { 0, 0, 0, 0 };
    
    // Items
    ScrollItem items[MAX_ITEMS];
    int item_count = 20;
    
    for (int i = 0; i < item_count; i++) {
        snprintf(items[i].name, sizeof(items[i].name), "Button %d - Click me!", i + 1);
        items[i].selected = false;
    }
    
    while (!WindowShouldClose()) {
        // Window dragging logic
        Rectangle title_bar = { window_bounds.x, window_bounds.y, window_bounds.width, 30 };
        Vector2 mouse_pos = GetMousePosition();
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && 
            CheckCollisionPointRec(mouse_pos, title_bar)) {
            drag_window = true;
            drag_offset = (Vector2){ mouse_pos.x - window_bounds.x, mouse_pos.y - window_bounds.y };
        }
        
        if (drag_window && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            window_bounds.x = mouse_pos.x - drag_offset.x;
            window_bounds.y = mouse_pos.y - drag_offset.y;
        }
        
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) drag_window = false;
        
        BeginDrawing();
        ClearBackground((Color){ 40, 40, 40, 255 });
        
        // Draw window
        bool exit_window = GuiWindowBox(window_bounds, "Scroll Panel Demo");
        if (exit_window) break;
        
        // Calculate scroll panel area
        Rectangle panel_area = {
            window_bounds.x + 10,
            window_bounds.y + 40,
            window_bounds.width - 20,
            window_bounds.height - 80
        };
        
        // Calculate content size (based on number of items)
        float content_height = item_count * ITEM_HEIGHT + 20;
        Rectangle content_rect = { 0, 0, panel_area.width - 20, content_height };
        
        // Draw scroll panel
        GuiScrollPanel(panel_area, "Scrollable Content", content_rect, &panel_scroll, &view_bounds);
        
        // Begin scissor mode for content clipping
        BeginScissorMode(view_bounds.x, view_bounds.y, view_bounds.width, view_bounds.height);
        
        // Draw items inside the scroll panel
        for (int i = 0; i < item_count; i++) {
            Rectangle item_rect = {
                panel_area.x + 10 - panel_scroll.x,
                panel_area.y + 10 + (i * ITEM_HEIGHT) + panel_scroll.y,
                panel_area.width - 30,
                ITEM_HEIGHT - 5
            };
            
            // Check if item is visible
            if (item_rect.y + item_rect.height > view_bounds.y && 
                item_rect.y < view_bounds.y + view_bounds.height) {
                
                // Draw selection highlight
                if (items[i].selected) {
                    DrawRectangleRec(item_rect, (Color){ 80, 120, 200, 100 });
                }
                
                // Draw button
                if (GuiButton(item_rect, items[i].name)) {
                    // Toggle selection on click
                    items[i].selected = !items[i].selected;
                    
                    // Optional: clear other selections for radio behavior
                    // for (int j = 0; j < item_count; j++) {
                    //     if (j != i) items[j].selected = false;
                    // }
                }
            }
        }
        
        EndScissorMode();
        
        // Status text at bottom of window
        int selected_count = 0;
        for (int i = 0; i < item_count; i++) {
            if (items[i].selected) selected_count++;
        }
        
        char status_text[100];
        snprintf(status_text, sizeof(status_text), 
                 "Selected: %d items", selected_count);
        DrawText(status_text, window_bounds.x + 10, 
                 window_bounds.y + window_bounds.height - 25, 10, 
                 (Color){ 200, 200, 200, 255 });
        
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
