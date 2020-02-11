#pragma once

#pragma region Default Parameters
#include "resource.h" 
#include <gl\gl.h>		// Header File For The OpenGL32 Library
#include <gl\glu.h>		// Header File For The GLu32 Library 
#include <math.h>		// Math library
#include <stdio.h>

int width = 1000;		//Screen width
int height = 1000;		//Screen Height 

int _hasGameStarted = 0;
double _timeWhenPause;
int _scoreWhenPause;
int _level;
int _Message;
int _gameOver;
GLuint PixelFormat;
HDC hDC = NULL;
HWND hWnd = NULL;
HGLRC hRC = NULL;

//Function prototype
int InitOpenGL();
void DrawGLScene();
void ShowWinLoss(int test);
void UpdateTimerBar();
void UpdateTimer();
void ReSizeGLScene(GLsizei width, GLsizei height);

#define MAX_LOADSTRING 100 

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
#pragma endregion Default Parameters


float degToRad(float degAngle) {
	double pi = 3.1415926535;
	return degAngle / 180.0 * pi;
}

// Fixes the Screen Size
#define EXTRA_WIDTH 16					
#define EXTRA_HEIGHT 60  



#pragma region Assignment2

#pragma region Program
#include "Program.h"
Program* pr = new Program;
#pragma endregion

#pragma region light
#include "Light.h"		// Light Script
Light* light = new Light;
#pragma endregion light

#include "Enemy.h"
Enemy* em = new Enemy;

#pragma endregion Assignment2


