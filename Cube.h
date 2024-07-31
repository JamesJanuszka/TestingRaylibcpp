#pragma once

#include"raylib-cpp.hpp"
class Cube
{
public:
	Cube();
	Cube(const raylib::Vector3& position, const raylib::Vector3& size, const raylib::Color& colour);
	virtual ~Cube();
	void Draw();

	raylib::Model* voxel;

private:
	raylib::Vector3 position;
	raylib::Vector3 size;
	raylib::Color colour;
	
};

