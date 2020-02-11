#pragma region include
#include "stdafx.h"
#include "Program.h"
#pragma endregion 
//Timer time;

#define Updates_per_Second 60.0f
__int64 startTimeInCounts = 0;
__int64 lastTimeInCounts = 0;
__int64 countsPerSecond;

Program::Program(){}
Program::~Program(){}

void Program::Draw(int _levels) {
	Draw3D_AxisSystem();
	#pragma region player
	glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
	player->DrawPlayer(GetTimePassedSinceStart());

	glPopMatrix(); // Restore matrix
	#pragma endregion player

	float _timeToWait = 1.0f;	//wait one second 
	float _timeToWait1 = 5.0f;	//wait one second 
	float _timeToWait2 = 10.0f;	//wait one second 
	float _timeToWait3 = 15.0f;	//wait one second 
	float _timeToWait4 = 20.0f;	//wait one second 
	float _timeToWait5 = 25.0f;	//wait one second 
	float _timeToWait6 = 30.0f;	//wait one second 
	float _timeToWait7 = 35.0f;	//wait one second 
	float _timeToWait8 = 40.0f;	//wait one second 
	float _timeToWait9 = 45.0f;	//wait one second 
	float _timeToWait10 = 50.0f;	//wait one second 
	float _timeToWait11 = 55.0f;	//wait one second 
	float _totalTime = GetTimePassedSinceStart();

	/*Switch statement used to spawn enemies*/
	switch (_levels) {
	case 1:
		if (GetTimePassedSinceStart() > _timeToWait) {
			_timeToWait += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(0, 0.5, 1, GetTimePassedSinceStart());
			em->DrawEnemy(0, 1.5, -5, GetTimePassedSinceStart());
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait1) {
			_timeToWait1 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(5, 6.5, 1, GetTimePassedSinceStart() - 5.0f);
			em->DrawEnemy(-3, 3.5, -5, GetTimePassedSinceStart() - 5.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait2) {
			_timeToWait2 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(7, 8.5, 1, GetTimePassedSinceStart() - 10.0f);
			em->DrawEnemy(3, 2.5, -5, GetTimePassedSinceStart() - 10.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait3) {
			_timeToWait3 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(-7, 1.5, 1, GetTimePassedSinceStart() - 15.0f);
			em->DrawEnemy(4, 0.5, -5, GetTimePassedSinceStart() - 15.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait4) {
			_timeToWait4 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(5, 6.5, 1, GetTimePassedSinceStart() - 20.0f);
			em->DrawEnemy(-5, 9.5, -5, GetTimePassedSinceStart() - 20.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait5) {
			_timeToWait5 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(2, 4.5, 1, GetTimePassedSinceStart() - 25.0f);
			em->DrawEnemy(-3, 2.5, -5, GetTimePassedSinceStart() - 25.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait6) {
			_timeToWait6 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(1, 4.5, 1, GetTimePassedSinceStart() - 30.0f);
			em->DrawEnemy(-1, 3.5, -5, GetTimePassedSinceStart() - 30.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait7) {
			_timeToWait7 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(9, 7.5, 1, GetTimePassedSinceStart() - 35.0f);
			em->DrawEnemy(4, 4.5, -5, GetTimePassedSinceStart() - 35.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait8) {
			_timeToWait8 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(-8, 6.5, 1, GetTimePassedSinceStart() - 40.0f);
			em->DrawEnemy(0, 2.5, -5, GetTimePassedSinceStart() - 40.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait9) {
			_timeToWait9 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(6, 1.5, 1, GetTimePassedSinceStart() - 45.0f);
			em->DrawEnemy(-3, 6.5, -5, GetTimePassedSinceStart() - 45.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait10) {
			_timeToWait10 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(3, 4.5, 1, GetTimePassedSinceStart() - 50.0f);
			em->DrawEnemy(-3, 6.5, -5, GetTimePassedSinceStart() - 50.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait11) {
			_timeToWait11 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(10, 1.5, 1, GetTimePassedSinceStart() - 55.0f);
			em->DrawEnemy(3, 3.5, -5, GetTimePassedSinceStart() - 55.0f);
			glPopMatrix(); // Restore matrix
		}
		break;
	case 2:
		if (GetTimePassedSinceStart() > _timeToWait) {
			_timeToWait += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(0, 0.5, 1, GetTimePassedSinceStart());
			em->DrawEnemy(0, 1.5, -5, GetTimePassedSinceStart());
			em->DrawEnemy(9, 7.5, -10, GetTimePassedSinceStart());
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait1) {
			_timeToWait1 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(5, 6.5, 1, GetTimePassedSinceStart() - 5.0f);
			em->DrawEnemy(-3, 3.5, -5, GetTimePassedSinceStart() - 5.0f);
			em->DrawEnemy(5, 3.5, -7, GetTimePassedSinceStart() - 5.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait2) {
			_timeToWait2 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(7, 8.5, 1, GetTimePassedSinceStart() - 10.0f);
			em->DrawEnemy(3, 2.5, -5, GetTimePassedSinceStart() - 10.0f);
			em->DrawEnemy(2, 1.5, -1, GetTimePassedSinceStart() - 10.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait3) {
			_timeToWait3 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(-7, 1.5, 1, GetTimePassedSinceStart() - 15.0f);
			em->DrawEnemy(4, 0.5, -5, GetTimePassedSinceStart() - 15.0f);
			em->DrawEnemy(9, 2.5, 3, GetTimePassedSinceStart() - 15.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait4) {
			_timeToWait4 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(5, 6.5, 1, GetTimePassedSinceStart() - 20.0f);
			em->DrawEnemy(-5, 9.5, -5, GetTimePassedSinceStart() - 20.0f);
			em->DrawEnemy(-1, 1.5, -2, GetTimePassedSinceStart() - 20.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait5) {
			_timeToWait5 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(2, 4.5, 1, GetTimePassedSinceStart() - 25.0f);
			em->DrawEnemy(-3, 2.5, -5, GetTimePassedSinceStart() - 25.0f);
			em->DrawEnemy(7, 6.5, -2, GetTimePassedSinceStart() - 25.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait6) {
			_timeToWait6 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(1, 4.5, 1, GetTimePassedSinceStart() - 30.0f);
			em->DrawEnemy(-1, 3.5, -5, GetTimePassedSinceStart() - 30.0f);
			em->DrawEnemy(-5, 0.5, -3, GetTimePassedSinceStart() - 30.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait7) {
			_timeToWait7 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(9, 7.5, 1, GetTimePassedSinceStart() - 35.0f);
			em->DrawEnemy(4, 4.5, -5, GetTimePassedSinceStart() - 35.0f);
			em->DrawEnemy(6, 6.5, 2, GetTimePassedSinceStart() - 35.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait8) {
			_timeToWait8 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(-8, 6.5, 1, GetTimePassedSinceStart() - 40.0f);
			em->DrawEnemy(0, 2.5, -5, GetTimePassedSinceStart() - 40.0f);
			em->DrawEnemy(5, 5.5, -1, GetTimePassedSinceStart() - 40.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait9) {
			_timeToWait9 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(6, 1.5, 1, GetTimePassedSinceStart() - 45.0f);
			em->DrawEnemy(-3, 6.5, -5, GetTimePassedSinceStart() - 45.0f);
			em->DrawEnemy(0, 3.5, 0, GetTimePassedSinceStart() - 45.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait10) {
			_timeToWait10 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(3, 4.5, 1, GetTimePassedSinceStart() - 50.0f);
			em->DrawEnemy(-3, 6.5, -5, GetTimePassedSinceStart() - 50.0f);
			em->DrawEnemy(2, 0.5, -3, GetTimePassedSinceStart() - 50.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait11) {
			_timeToWait11 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(10, 1.5, 1, GetTimePassedSinceStart() - 55.0f);
			em->DrawEnemy(3, 3.5, -5, GetTimePassedSinceStart() - 55.0f);
			em->DrawEnemy(-6, 8.5, 3, GetTimePassedSinceStart() - 55.0f);
			glPopMatrix(); // Restore matrix
		}
		break;
	case 3:
		if (GetTimePassedSinceStart() > _timeToWait) {
			_timeToWait += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(0, 0.5, 1, GetTimePassedSinceStart());
			em->DrawEnemy(0, 1.5, -5, GetTimePassedSinceStart());
			em->DrawEnemy(9, 7.5, 10, GetTimePassedSinceStart());
			em->DrawEnemy(9, 7.5, 10, GetTimePassedSinceStart());
			em->DrawEnemy(9, 7.5, -10, GetTimePassedSinceStart());
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait1) {
			_timeToWait1 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(5, 6.5, 1, GetTimePassedSinceStart() - 5.0f);
			em->DrawEnemy(-3, 3.5, -5, GetTimePassedSinceStart() - 5.0f);
			em->DrawEnemy(5, 3.5, -7, GetTimePassedSinceStart() - 5.0f);
			em->DrawEnemy(5, 3.5, 7, GetTimePassedSinceStart() - 5.0f);
			em->DrawEnemy(5, 3.5, -7, GetTimePassedSinceStart() - 5.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait2) {
			_timeToWait2 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(7, 8.5, 1, GetTimePassedSinceStart() - 10.0f);
			em->DrawEnemy(3, 2.5, -5, GetTimePassedSinceStart() - 10.0f);
			em->DrawEnemy(2, 1.5, -1, GetTimePassedSinceStart() - 10.0f);
			em->DrawEnemy(2, 1.5, 5, GetTimePassedSinceStart() - 10.0f);
			em->DrawEnemy(2, 1.5, -1, GetTimePassedSinceStart() - 10.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait3) {
			_timeToWait3 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(-7, 1.5, 1, GetTimePassedSinceStart() - 15.0f);
			em->DrawEnemy(4, 0.5, -5, GetTimePassedSinceStart() - 15.0f);
			em->DrawEnemy(4, 0.5, 5, GetTimePassedSinceStart() - 15.0f);
			em->DrawEnemy(4, 0.5, -5, GetTimePassedSinceStart() - 15.0f);
			em->DrawEnemy(9, 2.5, 3, GetTimePassedSinceStart() - 15.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait4) {
			_timeToWait4 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(5, 6.5, 1, GetTimePassedSinceStart() - 20.0f);
			em->DrawEnemy(-5, 9.5, -5, GetTimePassedSinceStart() - 20.0f);
			em->DrawEnemy(-1, 1.5, -2, GetTimePassedSinceStart() - 20.0f);
			em->DrawEnemy(-1, 1.5, -2, GetTimePassedSinceStart() - 20.0f);
			em->DrawEnemy(-1, 1.5, -2, GetTimePassedSinceStart() - 20.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait5) {
			_timeToWait5 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(2, 4.5, 1, GetTimePassedSinceStart() - 25.0f);
			em->DrawEnemy(-3, 2.5, -5, GetTimePassedSinceStart() - 25.0f);
			em->DrawEnemy(7, 6.5, -2, GetTimePassedSinceStart() - 25.0f);
			em->DrawEnemy(7, 6.5, -2, GetTimePassedSinceStart() - 25.0f);
			em->DrawEnemy(7, 6.5, -2, GetTimePassedSinceStart() - 25.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait6) {
			_timeToWait6 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(1, 4.5, 1, GetTimePassedSinceStart() - 30.0f);
			em->DrawEnemy(-1, 3.5, -5, GetTimePassedSinceStart() - 30.0f);
			em->DrawEnemy(-5, 0.5, -3, GetTimePassedSinceStart() - 30.0f);
			em->DrawEnemy(-5, 0.5, -3, GetTimePassedSinceStart() - 30.0f);
			em->DrawEnemy(-5, 0.5, -3, GetTimePassedSinceStart() - 30.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait7) {
			_timeToWait7 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(9, 7.5, 1, GetTimePassedSinceStart() - 35.0f);
			em->DrawEnemy(4, 4.5, -5, GetTimePassedSinceStart() - 35.0f);
			em->DrawEnemy(6, 6.5, 2, GetTimePassedSinceStart() - 35.0f);
			em->DrawEnemy(6, 6.5, 2, GetTimePassedSinceStart() - 35.0f);
			em->DrawEnemy(6, 6.5, 2, GetTimePassedSinceStart() - 35.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait8) {
			_timeToWait8 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(-8, 6.5, 1, GetTimePassedSinceStart() - 40.0f);
			em->DrawEnemy(0, 2.5, -5, GetTimePassedSinceStart() - 40.0f);
			em->DrawEnemy(5, 5.5, -1, GetTimePassedSinceStart() - 40.0f);
			em->DrawEnemy(5, 5.5, -1, GetTimePassedSinceStart() - 40.0f);
			em->DrawEnemy(5, 5.5, -1, GetTimePassedSinceStart() - 40.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait9) {
			_timeToWait9 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(6, 1.5, 1, GetTimePassedSinceStart() - 45.0f);
			em->DrawEnemy(-3, 6.5, -5, GetTimePassedSinceStart() - 45.0f);
			em->DrawEnemy(0, 3.5, 0, GetTimePassedSinceStart() - 45.0f);
			em->DrawEnemy(0, 3.5, 0, GetTimePassedSinceStart() - 45.0f);
			em->DrawEnemy(0, 3.5, 0, GetTimePassedSinceStart() - 45.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait10) {
			_timeToWait10 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(3, 4.5, 1, GetTimePassedSinceStart() - 50.0f);
			em->DrawEnemy(-3, 6.5, -5, GetTimePassedSinceStart() - 50.0f);
			em->DrawEnemy(2, 0.5, -3, GetTimePassedSinceStart() - 50.0f);
			em->DrawEnemy(2, 0.5, -3, GetTimePassedSinceStart() - 50.0f);
			em->DrawEnemy(2, 0.5, -3, GetTimePassedSinceStart() - 50.0f);
			glPopMatrix(); // Restore matrix
		}
		if (GetTimePassedSinceStart() > _timeToWait11) {
			_timeToWait11 += GetTimePassedSinceStart();
			glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
			em->DrawEnemy(10, 1.5, 1, GetTimePassedSinceStart() - 55.0f);
			em->DrawEnemy(3, 3.5, -5, GetTimePassedSinceStart() - 55.0f);
			em->DrawEnemy(3, 3.5, -5, GetTimePassedSinceStart() - 55.0f);
			em->DrawEnemy(3, 3.5, -5, GetTimePassedSinceStart() - 55.0f);
			em->DrawEnemy(-6, 8.5, 3, GetTimePassedSinceStart() - 55.0f);
			glPopMatrix(); // Restore matrix
		}
		break;
	}

	#pragma region em

	#pragma endregion em
}

void Program::Draw3D_AxisSystem() {
	glBegin(GL_LINES);
	// Draw positive x-axis as red
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(1000, 0, 0);
	// Draw positive y-axis as green
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1000, 0);
	// Draw positive z-axis as blue
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 1000);
	glEnd();
}

void Program::StartTimer(int _start) {

	if (_start == 1) {
		__int64 currentTimeInCounts;// countsPerSecond depends on your PC
		if (!QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSecond)) {
			MessageBox(NULL, L"QueryPerformanceFrequency Failed.", L"ERROR", MB_OK | MB_ICONINFORMATION); return;
		}
		QueryPerformanceCounter((LARGE_INTEGER*)&currentTimeInCounts);
		startTimeInCounts = currentTimeInCounts;
		lastTimeInCounts = currentTimeInCounts;
	}
	else {

	}

}

double Program::GetTimePassedSinceStart() {	// Return absolute time in seconds -since start
	__int64 currentTimeInCounts;
	double timePassedSeconds;

	// Calculate time passed in secondssince timer was started 
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTimeInCounts); timePassedSeconds = (currentTimeInCounts - startTimeInCounts) / (double)countsPerSecond;
	return  timePassedSeconds;
}

// Return relative time in seconds -since last measurement
double Program::GetTimePassedSinceLastTime() {
	__int64 currentTimeInCounts, timePassedSinceLastTimeInCounts;

	// Calculate time passed in seconds since last call to 
	// GetTimePassedSinceLastTime
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTimeInCounts);
	timePassedSinceLastTimeInCounts = currentTimeInCounts - lastTimeInCounts;
	double timePassedSinceLastTimeInSeconds = (currentTimeInCounts - lastTimeInCounts) / (double)countsPerSecond;
	lastTimeInCounts = currentTimeInCounts;
	return timePassedSinceLastTimeInSeconds;
}

void Program::StopTimer() {
	StartTimer(0);

}

void Program::DisplayTimer()
{
	const float _zAxis = 0.0f;
	GLfloat angle = 37.0f;
	glRotatef(angle, 0, 1, 0);
	glColor3f(1, 1, 1);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.5f, 7.5f, _zAxis);
	glVertex3f(9.5f, 7.5f, _zAxis);
	glVertex3f(9.5f, 8.0f, _zAxis);
	glVertex3f(-0.5f, 8.0f, _zAxis);
	glEnd();
}

void Program::UpdateTimer(float seconds) {

	float startPos = 9.5f;

	//every second that passes, minues 0.6f from bar
	float adjustment = seconds * 0.17f;
	float adjusted = startPos - adjustment;
	startPos = adjusted;
	glColor3f(0, 0, 1.0f);
	glRectf(adjusted , 7.51f, -0.49f, 7.99f);

	if (adjusted <= -2.0f) {
		//code that breaks game loop?
	}

}
