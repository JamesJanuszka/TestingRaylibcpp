#include "Window.h"

Window::Window(int width, int height, const std::string& title, int fps)
{
	window.Init(width, height, title);
	SetTargetFPS(fps);
	camera.SetPosition({ -5.0f, -5.0f, -5.0f });
	camera.SetTarget({ 0.0f, 0.0f, 0.0f });
	camera.SetUp({ 0.0f, 1.0f, 0.0f });
	camera.SetFovy(70.0f);
	camera.SetProjection(CAMERA_PERSPECTIVE);

	raylib::Vector3 position{ 0.0f,0.0f,0.0f };
	raylib::Vector3 size{ 1.0f,1.0f,1.0f };
	raylib::Color colour = GREEN;
	cube = Cube (position, size, colour);
}

void Window::Update()
{

}

void Window::Render()
{
	BeginDrawing();

	window.ClearBackground(DARKGRAY);

	camera.BeginMode();
	cube.Draw();
	camera.EndMode();


	EndDrawing();
}

bool Window::ShouldClose() const
{
	return window.ShouldClose();
}
