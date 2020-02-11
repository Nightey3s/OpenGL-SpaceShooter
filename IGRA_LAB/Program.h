#pragma region include
#pragma once
#include <gl\gl.h> // Header File For The OpenGL32 Library 
#include <gl\glu.h> // Header File For The GLu32 Library
#include "Player.h"	// Player script
#include "Enemy.h"	// Enemy script
#pragma endregion include

class Program
{
public:
	void Draw(int _levels);				// The Draw function which will be called in the IGRA_LAB.cpp
	void Draw3D_AxisSystem();	// altered 3D axis system
	void StartTimer(int _start);
	void StartTimer();
	double GetTimePassedSinceStart();
	double GetTimePassedSinceLastTime();
	void StopTimer();
	void DisplayTimer();
	void UpdateTimer(float seconds);
	Program(); ~Program();

	// Player Scripts
	#pragma region player
	Player* player = new Player;
	#pragma endregion player

	// Enemy Scripts
	#pragma region enemy
	Enemy* em = new Enemy;
	#pragma endregion enemy
};