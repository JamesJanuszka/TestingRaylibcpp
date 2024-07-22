#pragma once
#include<string>
#include "raylib-cpp.hpp"

class Window
{
public:
	Window(int width, int height, std::string title, int fps);
	void Render();
	bool ShouldClose();

private:
	raylib::Window window;
};

