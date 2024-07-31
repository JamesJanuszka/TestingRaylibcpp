#include "Cube.h"

Cube::Cube()
{
}

Cube::Cube(const raylib::Vector3& position, const raylib::Vector3& size, const raylib::Color& colour) : position{ position }, size{ size }, colour{ colour }
{
	raylib::Model* temp = new raylib::Model (raylib::Mesh::Cube(this->size.x, this->size.y, this->size.z));
	//raylib::Mesh mesh;
	voxel = temp;
}

Cube::~Cube()
{

}

void Cube::Draw()
{
	//DrawCubeV(position, size, colour);
	//position.DrawCube(size, colour);
	voxel->Draw(position, 1.0f ,colour);
	voxel->Draw({ 10.0f, 0.0f,0.0f }, 5.0f, colour);

}
