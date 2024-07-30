#include "Cube.h"

Cube::Cube()
{
}

Cube::Cube(const raylib::Vector3& position, const raylib::Vector3& size, const raylib::Color& colour) : position{ position }, size{ size }, colour{ colour }
{
}

Cube::~Cube()
{
}

void Cube::Draw()
{
	//DrawCubeV(position, size, colour);
	position.DrawCube(size, colour);
}
