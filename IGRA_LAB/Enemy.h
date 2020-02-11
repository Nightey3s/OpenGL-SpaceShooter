#pragma region include
#pragma once
#include <gl\gl.h> // Header File For The OpenGL32 Library 
#include <gl\glu.h> // Header File For The GLu32 Library


class Enemy
{
public:
	void DrawEnemy(float x, float y, float z, float time);		// This is called to draw the enemy	and input its position
	void DrawDiamond(float x, float y, float z, float testcolor);
	void DrawDiamond(float x, float y, float z);	// (x, y, z)position
	void Move();
	void SetColor(int color);
	Enemy(); ~Enemy();

	#pragma region Rotation
	float speed = 0;
	int colors;
	float yRotation = 0;
	double rotationalVelicityInDegreesPerSeconds = 50.0;
	#pragma endregion Rotation
};

