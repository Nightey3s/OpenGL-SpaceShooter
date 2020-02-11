#pragma region include
#pragma once
#include <gl\gl.h> // Header File For The OpenGL32 Library 
#include <gl\glu.h> // Header File For The GLu32 Library
#pragma endregion include

class Player
{ 
public: 
	void DrawPlayer(float time);								// This is called to draw the player		
	void DrawPyramid(float x, float y, float z);	// (x, y, z)position
	void DrawCube();
	Player(); ~Player();

	#pragma region Rotation
	float speed = 0;
	float yRotation = 0;
	double rotationalVelicityInDegreesPerSeconds = 50.0;
	#pragma endregion Rotation
};

