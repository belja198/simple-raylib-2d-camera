#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 500

struct Block {
    float pos_x, pos_y;
    float height, width;
    Color color;
};

struct Arrow {
    Rectangle rect;
    Vector2 points[3];
};



int main() 
{
    // Initialization
    //--------------------------------------------------------------------------------------
    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib");

    Camera2D camera = {};
    camera.target = (Vector2){ SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f };
    camera.offset = (Vector2){ SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    Block blocks[50];
    int num_blocks = 0;

    blocks[0].pos_x = SCREEN_WIDTH/2.0f;
    blocks[0].pos_y = SCREEN_HEIGHT/2.0f;
    blocks[0].width = 40;
    blocks[0].height = 40;
    blocks[0].color = DARKPURPLE;
    num_blocks++;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_W))
            camera.target.y -= 500.0f * GetFrameTime();

        if (IsKeyDown(KEY_S))
            camera.target.y += 500.0f * GetFrameTime();

        if (IsKeyDown(KEY_A))
            camera.target.x -= 500.0f * GetFrameTime();

        if (IsKeyDown(KEY_D))
            camera.target.x += 500.0f * GetFrameTime();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) ) {
            Vector2 mouse_pos = GetMousePosition();

            if (CheckCollisionPointRec(mouse_pos, Rectangle{blocks[0].pos_x, blocks[0].pos_y, blocks[0].width, blocks[0].height})) {

            }
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            
            ClearBackground(RAYWHITE);

            BeginMode2D(camera);
                //TODO
                DrawText("This is some text", 150, 150, 30, MAGENTA);
                DrawRectangle(blocks[0].pos_x, blocks[0].pos_y, blocks[0].width, blocks[0].height, blocks[0].color);


            EndMode2D();

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}