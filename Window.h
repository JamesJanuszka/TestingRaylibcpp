#pragma once
#include<string>
#include "raylib-cpp.hpp"
#include "Cube.h"

class Window
{
public:
	Window(int width, int height, const std::string& title, int fps);
	void Update();
	void Render();
	bool ShouldClose() const;

private:
	raylib::Window window;
	raylib::Camera3D camera;
	Cube cube;
};

