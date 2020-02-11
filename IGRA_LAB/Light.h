#pragma region include
#pragma once
#include <gl\gl.h> // Header File For The OpenGL32 Library 
#include <gl\glu.h> // Header File For The GLu32 Library
#pragma endregion include

class Light
{
public:
	void DrawLight();
	void SetupLight();
	Light(); ~Light();
};

