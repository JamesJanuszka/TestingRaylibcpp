#pragma once
#include<string>
#include<iostream>
#include <filesystem>
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
	bool SetupShader(const std::filesystem::path& vertex_shader, const std::filesystem::path& fragment_shader);
	raylib::Window window;
	raylib::Camera3D camera;
	raylib::Shader shader;
	Cube cube;
	int* shaderDefaultLocs;
};

