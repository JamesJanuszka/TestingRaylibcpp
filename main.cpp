#include <string>
#include "Window.h"


int main() {
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