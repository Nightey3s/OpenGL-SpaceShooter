#pragma region include
#include "stdafx.h"
#include "Player.h"
#pragma endregion

Player::Player() {}
Player::~Player(){}
void Player::DrawPlayer(float time) {		// Use this to Draw the player
	//DrawPyramid(10.2, 0, 13.5); // (x, y, z)position
	#pragma region Rotation
	speed = 5;
	yRotation = time * speed *rotationalVelicityInDegreesPerSeconds;
	glPushMatrix();
	glTranslatef(10.2, 0, 13.5);	// Translates this object, Translate(x, y ,z);
	glRotatef(yRotation, 0, 1, 0);	// Rotate this object, Rotate(Angle, x, y, z);
	DrawPyramid(10.2, 0, 13.5); // (x, y, z)position
	glPopMatrix();
	#pragma endregion Rotation
}

// Player's Model
void Player::DrawPyramid(float x, float y, float z) {
	
	glEnable(GL_LIGHTING); // This will ensure the cube to be lit when drawn
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);		// Vertices in clockwise order
	//glRotatef(0, 0, 1, 0);	// Rotate this object, Rotate(Angle, x, y, z);
	//glTranslatef(x, y, z); // Translates this object, Translate(x, y ,z);
	glPolygonMode(GL_FRONT, GL_FILL); // Solid cube
	GLfloat blue[] = { 0,0,1,0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);	//onced we have this, we dont need all the "glColor3f"
	
	// Vertices in clock wise order v0, v1, v2, v3
	// Front Face in green
	glBegin(GL_TRIANGLES); // 0, 1, 2, 3				// green face //front
	glNormal3f(0, 0, 1);	// The surface normal
	glVertex3f(	0,	1,	0);	// v0 Top
	glVertex3f(	1, -1,	1);	// v1 Bottom Right
	glVertex3f(-1, -1,	1);	// v2 Bottom Left
	glEnd();

	glBegin(GL_TRIANGLES); // 0, 1, 2, 3				// blue face //right
	glNormal3f(1, 0, 0);	// The surface normal
	glVertex3f(	0,	1,	0);	// v0 
	glVertex3f(	1, -1, -1);	// v1 
	glVertex3f(	1, -1,	1);	// v2 
	glEnd();

	glBegin(GL_TRIANGLES); // 0, 1, 2, 3				// red face //back
	glNormal3f(0, 0, -1);	// The surface normal
	glVertex3f(	0,	1,	0);	// v0 
	glVertex3f(-1, -1, -1);	// v1 
	glVertex3f(	1, -1, -1);	// v2 
	glEnd();

	glBegin(GL_TRIANGLES); // 0, 1, 2, 3				// yellow face //left
	glNormal3f(-1, 0, 0);	// The surface normal
	glVertex3f(	0,	1,	0);	// v0 
	glVertex3f(-1, -1,	1);	// v1 
	glVertex3f(-1, -1, -1);	// v2 
	glEnd();

	glBegin(GL_TRIANGLES); // 0, 1, 2, 3				// yellow face //bottom of left
	glNormal3f(0, -1, 0);	// The surface normal
	glVertex3f(	1, -1,	1);	// v2 
	glVertex3f(-1, -1, -1);	// v1 
	glVertex3f(-1, -1,	1);	// v0  
	glEnd();

	glBegin(GL_TRIANGLES); // 0, 1, 2, 3				// yellow face //bottom of right
	glNormal3f(0, -1, 0);	// The surface normal
	glVertex3f(	1, -1,	1);	// v2 
	glVertex3f(	1, -1, -1);	// v1 
	glVertex3f(-1, -1, -1);	// v0  
	glEnd();
	glDisable(GL_LIGHTING); // this will ensure that other stuff we draw, such as the axis system will not be lit when drawn.
}

void Player::DrawCube() {

	int cubeIndices[] = {
		0, 1, 2, 3, // Front Face
		7, 6, 5, 4, // Back Face
		2, 6, 7, 3, // Right Face
		0, 4, 5, 1, // Left Face
		1, 5, 6, 2, // Top Face
		3, 7, 4, 0 // Bottom Face
	};

	float cubeColors[][3] = {
		0, 1, 0, // Front is Green
		1, 0, 0, // Back is Red
		0, 0, 1, // Right is Blue
		1, 1, 0, // Left is Yellow
		0, 0, 0, // Top is Black
		0.5, 0.5, 0.5 // Bottom is Grey
	};

	float cubeVertices[][3] = {
		{ -1.0f, -1.0f, 1.0f }, // v0
		{ -1.0f, 1.0f, 1.0f }, // v1
		{ 1.0f, 1.0f, 1.0f }, // v2
		{ 1.0f, -1.0f, 1.0f }, // v3
		{ -1.0f, -1.0f, -1.0f }, // v4
		{ -1.0f, 1.0f, -1.0f }, // v5
		{ 1.0f, 1.0f, -1.0f }, // v6
		{ 1.0f, -1.0f, -1.0f }, // v7
	};

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW); // Front face is clockwise
	glPolygonMode(GL_FRONT, GL_FILL);
	glColor3f(0.0, 0.0, 0.0);
	// The index in cubeIndices array
	// points to next vertex to draw.
	int index = 0;
	// Draw the cube quad by quad
	for (int qd = 0; qd < 6; qd++) {
		glBegin(GL_QUADS);
		glColor3f(cubeColors[qd][0], cubeColors[qd][1],
			cubeColors[qd][2]);
		for (int v = 0; v < 4; v++) {// Four vertices for one quad
			glVertex3f(cubeVertices[cubeIndices[index]][0],
				cubeVertices[cubeIndices[index]][1],
				cubeVertices[cubeIndices[index]][2]);
			index++; // Move to next vertex in quad
		}
		glEnd();
	}
}