#include "Window.h"

Window::Window(int width, int height, const std::string& title, int fps)
{
	window.Init(width, height, title);
	SetTargetFPS(fps);
	camera.SetPosition({ -5.0f, 5.0f, -5.0f });
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
	float offset = 3.0f * GetFrameTime();

	if (IsKeyDown(KEY_W))
	{
		camera.position.x -= offset;
		camera.target.x -= offset;
	}
	else if (IsKeyDown(KEY_S))
	{
		camera.position.x += offset;
		camera.target.x += offset;
	}

	if (IsKeyDown(KEY_A))
	{
		camera.position.z -= offset;
		camera.target.z -= offset;
	}

	else if (IsKeyDown(KEY_D))
	{
		camera.position.z += offset;
		camera.target.z += offset;
	}

	camera.position.y += GetMouseWheelMoveV().y;
	if (camera.position.y < 3.0f)
	{
		camera.position.y = 3.0f;
	}
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
