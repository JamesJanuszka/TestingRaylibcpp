#include "Window.h"

Window::Window(int width, int height, std::string title, int fps)
{
	window.Init(width, height, title);
	SetTargetFPS(fps);
}

void Window::Render()
{
	BeginDrawing();

	window.ClearBackground(RAYWHITE);

	DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);



	EndDrawing();
}

bool Window::ShouldClose()
{
	return window.ShouldClose();
}
