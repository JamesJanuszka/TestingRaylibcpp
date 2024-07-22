#include <string>
#include "Window.h"


int main() {
    int screenWidth = 800;
    int screenHeight = 450;
    std::string title("raylib-cpp - basic window");
    int fps = 60;


    Window window(screenWidth, screenHeight, title, fps);
    //raylib::Texture logo("raylib_logo.png");

    //SetTargetFPS(60);

    while (!window.ShouldClose())
    {
        window.Render();
    }

    // UnloadTexture() and CloseWindow() are called automatically.

    return 0;
}