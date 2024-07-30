//#define GRAPHICS_API_OPENGL_43

#include <string>
#include "Window.h"



int main() {
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 450;
    std::string title("raylib-cpp - basic window");
    constexpr int fps = 60;


    Window window(screenWidth, screenHeight, title, fps);
    //raylib::Texture logo("raylib_logo.png");

    //SetTargetFPS(60);

    while (!window.ShouldClose())
    {
        window.Update();
        window.Render();
    }

    // UnloadTexture() and CloseWindow() are called automatically.

    return 0;
}