
//Done by: 
//Brian


#include "stdafx.h"					//should be the very first to be included
#include "IGRA_LAB.h" 
#include "resource.h"
#include <iostream>
#include <string>
#include <thread>

void DrawGLScene() {				// Scene Controller
	
	if (_hasGameStarted == 1) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 1);		// Background Colour of Window (R,G,B,A)
#pragma region Assignment2
	// Locate camera in the (1,1,1) position then look at
	// origin (the intersection of the axis system)
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(15, 5, 20, // Camera's position   // (?, ?, Distance) // 5,5,-10 to look at the back //15,5,20 //5,3,10
			0, 0, 0, // Camera's target to look at
			0, 1, 0); // Orientation of camera
		glPushMatrix(); // Save the matrix //this stops the object to rotate the whole axis when we just want to rotate the object only
		if (!_level) { _level = 1; }
		pr->Draw(_level); /* To do: pass in level number to decide speed/num of enemy */
		pr->DisplayTimer();
		//start the game here
		UpdateTimerBar();
		glPopMatrix(); // Restore matrix
	}
	else {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 1);		// Background Colour of Window (R,G,B,A)
		
	}	
	if (pr->GetTimePassedSinceStart() >= 60.0f) {
		_hasGameStarted = 0;
		if (false) {//win condition - replace true with winning condition
			_gameOver = 1;
		}
		else if(true){	//replace false with losing condition
			_gameOver = 2;
		}
	}


#pragma endregion Assignment2
}

void ShowWinLoss(int test) {

	if (test == 1)	//win condition 
	{
		MessageBoxA(NULL, "You Win \r\n\n You are ready for the next stage", "Win", MB_OK);

	}
	else if (test == 2) {
		MessageBoxA(NULL, "You Lose \r\n\n Try harder next time", "Lose", MB_OK);
	}

}

void UpdateTimerBar() {
	UpdateTimer();	//this updates the time in seconds on the title bar
	float Seconds = pr->GetTimePassedSinceStart();//get the time in seconds
	pr->UpdateTimer(Seconds);
}

void UpdateTimer() {//Use this to update timer and score in title bar
	double timePassedAbsInSeconds = pr->GetTimePassedSinceStart();
	glPushMatrix();
	float textT = pr->GetTimePassedSinceStart();
	std::string text = "Space Shooter              Time:     " + std::to_string(textT) + "           Score: ";
	SetWindowTextA(hWnd, text.c_str());//Set title bar

	glPopMatrix();
}

//Structure for OpenGL Config
static PIXELFORMATDESCRIPTOR pfd{
 sizeof(PIXELFORMATDESCRIPTOR),
 1,// Version Number
 PFD_DRAW_TO_WINDOW |		// Format Must Support Window
 PFD_SUPPORT_OPENGL |		// Format Must Support OpenGL
 PFD_DOUBLEBUFFER,			// Must Support Double Buffering
 PFD_TYPE_RGBA,				// Request An RGBA Format
 16,						// Select Our Color Depth = 16
 0, 0, 0, 0, 0, 0,			// Color Bits Ignored
 0,							// No Alpha Buffer
 0,							// Shift Bit Ignored
 0,							// No Accumulation Buffer
 0, 0, 0, 0,				// Accumulation Bits Ignored
 32,						// 32 Bit Z-Buffer (Depth Buffer)
 0,							// No Stencil Buffer
 0,							// No Auxiliary Buffer
 PFD_MAIN_PLANE,			// Main Drawing Layer
 0,							// Reserved
 0, 0, 0					// Layer Masks Ignored
};

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.


	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_IGRALAB, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_IGRALAB));

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{

		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			// Added for IGRA

			DrawGLScene();

			SwapBuffers(hDC);
		}
	}
	return (int)msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_IGRALAB));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_IGRALAB);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	/* Updated for IGRA
	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	   CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr); */

	   // Creates The Window
	//((GetSystemMetrics(SM_CXSCREEN) / 2)) - ((width + EXTRA_WIDTH)/2)
	hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW ^ WS_MINIMIZEBOX ^ WS_MAXIMIZEBOX ^ WS_THICKFRAME, ((GetSystemMetrics(SM_CXSCREEN) / 2)) - ((width + EXTRA_WIDTH) / 2), 0, (width + EXTRA_WIDTH ), (height + EXTRA_HEIGHT), nullptr, nullptr, hInstance, nullptr);//I made the main game window right in the center

	SetWindowText(hWnd, TEXT("\r\nSpace Shooter"));//Set title bar


	//HWND hWnd2 = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW ^ WS_MINIMIZEBOX ^ WS_MAXIMIZEBOX ^ WS_THICKFRAME, ((GetSystemMetrics(SM_CXSCREEN) / 2)) - ((width + EXTRA_WIDTH) / 2), 0, (width + EXTRA_WIDTH), (height + EXTRA_HEIGHT), nullptr, nullptr, hInstance, nullptr);
	InitOpenGL();
	SetTimer(hWnd, 0,1,NULL);
	if (!hWnd) { return FALSE; }
	/*CheckMenuItem(GetMenu(hWnd), ID_SPHERE_DESELECT, MF_CHECKED);*/	//defaults to checked on start
	CheckMenuItem(GetMenu(hWnd), ID_LEVELS_LEVEL1, MF_CHECKED);	//defaults to checked on start
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	ReSizeGLScene(width, height);
	return TRUE;
}


// Mouse/Keyboard Input

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//   
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {

#pragma region Others
	case WM_COMMAND: {//menu items press
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About); break;
		case IDM_EXIT:
			_hasGameStarted = 0;
			DestroyWindow(hWnd); break;
		case ID_GAME_START:
			//start game


			pr->StartTimer(1);//will need to move this to only start when game starts
			_hasGameStarted = 1; //switch to 0 to stop time

			break;
		case ID_GAME_PAUSE:
			//Might not be doable
			_timeWhenPause = pr->GetTimePassedSinceStart();
			_hasGameStarted = 2;

			break;
		case ID_GAME_STOP:
			//Stops
			_hasGameStarted = 0;
			break;
		case ID_LEVELS_LEVEL1: 
			CheckMenuItem(GetMenu(hWnd), ID_LEVELS_LEVEL1, MF_CHECKED);
			CheckMenuItem(GetMenu(hWnd), ID_LEVELS_LEVEL2, MF_UNCHECKED);
			CheckMenuItem(GetMenu(hWnd), ID_LEVELS_LEVEL3, MF_UNCHECKED);
			_level = 1;
			break; 
		case ID_LEVELS_LEVEL2: 
			CheckMenuItem(GetMenu(hWnd), ID_LEVELS_LEVEL2, MF_CHECKED);
			CheckMenuItem(GetMenu(hWnd), ID_LEVELS_LEVEL1, MF_UNCHECKED);
			CheckMenuItem(GetMenu(hWnd), ID_LEVELS_LEVEL3, MF_UNCHECKED);
			_level = 2;
			break; 
		case ID_LEVELS_LEVEL3: 
			CheckMenuItem(GetMenu(hWnd), ID_LEVELS_LEVEL3, MF_CHECKED);
			CheckMenuItem(GetMenu(hWnd), ID_LEVELS_LEVEL2, MF_UNCHECKED);
			CheckMenuItem(GetMenu(hWnd), ID_LEVELS_LEVEL1, MF_UNCHECKED);
			_level = 3;
			break; 
		case ID_GAME_RESUME:

			break;
		case IDD_LoseMessage:
		//	DialogBox(hInst, MAKEINTRESOURCE(IDD_LoseMessage), hWnd, About);
			
			MessageBoxA(NULL, "You Lose \r\n\n Try harder next time", "Lose", MB_OK);
			break;

		case IDD_WinMessage:
		//	DialogBox(hInst, MAKEINTRESOURCE(IDD_WinMessage), hWnd, About);

			
			break;
		case ID_GAME_SHOWRESULTS:
			if (_gameOver == 1) {
				MessageBoxA(NULL, "You Win \r\n\n You are ready for the next stage", "Win", MB_OK);
			}
			else {
				MessageBoxA(NULL, "You Lose \r\n\n Try harder next time", "Lose", MB_OK);
			}
			break;
			//case ID_SPHERE_SELECT: 
			//	//code
			//	CheckMenuItem(GetMenu(hWnd), ID_SPHERE_SELECT, MF_CHECKED);
			//	CheckMenuItem(GetMenu(hWnd), ID_SPHERE_DESELECT, MF_UNCHECKED);
			//	
			//	break;

			//case ID_SPHERE_DESELECT:
			//	//code
			//	CheckMenuItem(GetMenu(hWnd), ID_SPHERE_DESELECT, MF_CHECKED);
			//	CheckMenuItem(GetMenu(hWnd), ID_SPHERE_SELECT, MF_UNCHECKED);
			//	break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	} break;
	case WM_TIMER: {

	break;
	}
	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...

		EndPaint(hWnd, &ps);
	} break;
	case WM_DESTROY: {
		PostQuitMessage(0);
		break;
	}
#pragma endregion
#pragma region Unit01
	case WM_SIZE: {
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam)); break;
	}
#pragma endregion Unit01

#pragma region Unit02

#pragma region Mouse
	case WM_LBUTTONDOWN: {
		// Get the left mouse press coordinates
		int mouseX = LOWORD(lParam);
		int mouseY = HIWORD(lParam);
#pragma region Check Input
		/*char message[255];
		sprintf_s(message, "x=%d, y=%d", mouseX, mouseY);
		MessageBoxA(NULL, message, "Mouse Press Event" , MB_OK | MB_ICONINFORMATION);*/#pragma endregion 

		// Circle
	/*	xPosCircle = 0.3;
		yPosCircle = 0.3;*/
		//convertWindowToOpenGLCoordinates(mouseX, mouseY, xPosCircle, yPosCircle); 

		//Lab Task:	//2.3
		//convertWindowToOpenGLCoordinates(mouseX, mouseY, xPosSquare, yPosSquare);
		//sq->HandleLButtonDown(xPosSquare, yPosSquare);
		break;
	}	case WM_MOUSEMOVE: {
		// Get the left mouse press coordinates
		int mouseX = LOWORD(lParam);
		int mouseY = HIWORD(lParam);

		break;
	}	case WM_LBUTTONUP: {

		break;
	}
#pragma endregion

	case WM_KEYDOWN: {									//When Keyboard Key is pressed down
		switch (wParam) {
		case VK_DELETE: {							// When Delete Button is pressed

		} break;

		case VK_SHIFT: {							// When Shift Button is pressed

		} break;

		case 0x1b: {
			PostQuitMessage(0);
		}
		default: break;
		}
#pragma region Check Input
		/*char message[32];
		sprintf_s(message, "WM_KEYDOWN: 0x%x\n", wParam);
		MessageBoxA(NULL, message, "Key Press Event", MB_OK | MB_ICONINFORMATION); */
#pragma endregion 
	} break;

	case WM_KEYUP: {					//When Keyboard Key is released			
		switch (wParam) {
		case VK_SHIFT: {			// When Shift Button is released			
		} break;
		default: break;
		}
	}

#pragma endregion Unit02

	default: {
		return DefWindowProc(hWnd, message, wParam, lParam);

	}
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message) {
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:

		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;

		}
		break;
	}
	return (INT_PTR)FALSE;
}
// Message handler for about box.
INT_PTR CALLBACK Win(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message) {
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:

		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;

		}
		break;
	}
	return (INT_PTR)FALSE;
}

// ADDED FOR IGRA	 
void ReSizeGLScene(GLsizei width, GLsizei height) {
	if (height == 0)// Prevent A Divide By Zero By
		height = 1; // Making Height Equal One
		// Reset The Current Viewport
	glViewport(0, 0, width, height);
	// Select The Projection Matrix
	glMatrixMode(GL_PROJECTION);
	// Reset The Projection Matrix
	glLoadIdentity();
	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
}
int InitOpenGL() {
	// Get Device Dontext
	if (!(hDC = GetDC(hWnd))) {
		MessageBox(NULL, L"Can't Create A GL Device Context.", L"ERROR", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}
	// Check if Windows can find a matching Pixel Format
	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd))) {
		MessageBox(NULL, L"Can't Find A Suitable PixelFormat.", L"ERROR", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}
	// Try to set pixel format
	if (!SetPixelFormat(hDC, PixelFormat, &pfd)) {
		MessageBox(NULL, L"Can't Set The PixelFormat.", L"ERROR", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}
	// Get a Rendering context
	if (!(hRC = wglCreateContext(hDC))) {
		MessageBox(NULL, L"Can't Create A GL Rendering Context.", L"ERROR", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}
	// Activate Rendering Context
	if (!wglMakeCurrent(hDC, hRC)) {
		MessageBox(NULL, L"Can't Activate The GL Rendering Context.", L"ERROR", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}

	// TO SOLVE DEPTH-BUFFER ISSUE
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	#pragma region Assignment2
	light->DrawLight();

	#pragma endregion Assignment2
	return 1;
}