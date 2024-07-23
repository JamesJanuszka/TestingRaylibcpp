#pragma once
#include<string>
#include "raylib-cpp.hpp"

class Window
{
public:
	Window(int width, int height, const std::string& title, int fps);
	void Render();
	bool ShouldClose() const;

private:
	raylib::Window window;
};

