#include "Window.h"

Window::Window(int width, int height, const std::string& title, int fps) : shader (0)
{
	window.Init(width, height, title);
	SetTargetFPS(fps);
	camera.SetPosition({ -5.0f, 5.0f, -5.0f });
	camera.SetTarget({ 0.0f, 0.0f, 0.0f });
	camera.SetUp({ 0.0f, 1.0f, 0.0f });
	camera.SetFovy(70.0f);
	camera.SetProjection(CAMERA_PERSPECTIVE);
	raylib::Vector3 position{ 0.0f,0.5f,0.0f };
	raylib::Vector3 size{ 1.0f,1.0f,1.0f };
	raylib::Color colour = GREEN;
	cube = Cube (position, size, colour);

	std::filesystem::path vertex_shader = "./resources/shaders/basic_lighting.vert";
	std::filesystem::path fragment_shader = "./resources/shaders/basic_lighting.frag";
	SetupShader(vertex_shader, fragment_shader);

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
		//camera.position.y = 3.0f;
	}
	float cameraPos[3]{ camera.position.x, camera.position.y, camera.position.z };
	shader.SetValue(shaderDefaultLocs[SHADER_LOC_VECTOR_VIEW], cameraPos, SHADER_UNIFORM_VEC3);
}

void Window::Render()
{
	BeginDrawing();

	window.ClearBackground(DARKGRAY);

	camera.BeginMode();
	shader.BeginMode();
	cube.Draw();
	DrawGrid(64, 4.0f);
	camera.EndMode();
	shader.EndMode();
	


	EndDrawing();
}

bool Window::ShouldClose() const
{
	return window.ShouldClose();
}

bool Window::SetupShader(const std::filesystem::path& vertex_shader, const std::filesystem::path& fragment_shader)
{
	shader = raylib::Shader::Load(vertex_shader.string(), fragment_shader.string());

	shaderDefaultLocs = shader.GetLocs();
	shaderDefaultLocs[SHADER_LOC_VECTOR_VIEW] = shader.GetLocation("viewPos");

	int ambientLoc = shader.GetLocation("ambient");
	float value[4]{ 0.1f, 0.1f, 0.1f, 0.0f };
	shader.SetValue(ambientLoc, &value, SHADER_UNIFORM_VEC4);

	// Shader info
	//int type;
	//bool enabled;
	//Vector3 position;
	//Vector3 target;
	//Color color;
	//float attenuation;

	//int enabled;
	//int type;
	//vec3 position;
	//vec3 target;
	//vec4 color;

	int enabledLoc = shader.GetLocation("lights[0].enabled");
	int typeLoc = shader.GetLocation("lights[0].type");
	int positionLoc = shader.GetLocation("lights[0].position");
	int targetLoc = shader.GetLocation("lights[0].target");
	int colorLoc = shader.GetLocation("lights[0].color");
	int attenuationLoc = shader.GetLocation("lights[0].attenuation");

	int type{ 0 };
	int enabled{ 1};
	float position[3]{ -2.0f, 9.0f, -1.0f };
	float target[3]{ 4.0f, 0.0f, 4.0f };
	raylib::Vector4 col = raylib::Color(WHITE).Normalize() ;
	float color[4]{col.x/5, col.y/5, col.z/5, col.w/5};
	//float color[4]{ 0.2f, 0.2f, 0.2f, 0.9f };
	float attenuation{ 1.0f };

	shader.SetValue(enabledLoc, &enabled, SHADER_UNIFORM_INT);
	shader.SetValue(typeLoc, &type, SHADER_UNIFORM_INT);
	shader.SetValue(positionLoc, position, SHADER_UNIFORM_VEC3);
	shader.SetValue(targetLoc, target, SHADER_UNIFORM_VEC3);
	shader.SetValue(colorLoc, color, SHADER_UNIFORM_VEC4);


	return shader.IsReady();
}
