#pragma region include
#include "stdafx.h"
#include "Enemy.h"
#pragma endregion

int colors = 1;
Enemy::Enemy(){}
Enemy::~Enemy(){}

void Enemy::DrawEnemy(float x, float y, float z, float time) {	// Use this to Draw the enemy and it's position
	
	float _xTransform = 10.2f - x;
	float _yTransform = 0.0f - y;
	float _zTransform = 13.5f - z;

	float _xMove = time * _xTransform * 0.1f;
	float _yMove = time * _yTransform * 0.1f;
	float _zMove = time * _zTransform * 0.1f;
	
	float _colortest = 8;
	float _colorFade = (_colortest - time )* 0.5f;
	//DrawDiamond(_xMove, _yMove, _zMove);
	#pragma region Rotation
	speed = 10;
	yRotation = time * rotationalVelicityInDegreesPerSeconds * speed;
	glPushMatrix();
	glTranslatef(_xMove, _yMove, _zMove);	// Translates this object, Translate(x, y ,z);
	glRotatef(yRotation, 0, 1, 0);	// Rotate this object, Rotate(Angle, x, y, z);
	DrawDiamond(_xMove, _yMove, _zMove, _colorFade);
	glPopMatrix();
	#pragma endregion Rotation
}

//Enemy's Model
void Enemy::DrawDiamond(float x, float y, float z, float time) {
	glEnable(GL_LIGHTING); // This will ensure the cube to be lit when drawn
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);		// Vertices in clockwise order
	//glRotatef(0, 0, 1, 0);	// Rotate this object, Rotate(Angle, x, y, z);
	//glTranslatef(x, y, z);	// Translates this object, Translate(x, y ,z);
	glPolygonMode(GL_FRONT, GL_FILL); // Solid cube
	GLfloat red[] = { time,0,0,0 };

		
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);	//onced we have this, we dont need all the "glColor3f"
	// Vertices in clock wise order v0, v1, v2, v3

		// Top Part
	glBegin(GL_TRIANGLES); // 0, 1, 2, 3				//front
	glNormal3f(0, 0, 1);	// The surface normal
	glVertex3f(0,	1,	0);	// v0 Top
	glVertex3f(.2,	0, .2);	// v1 Bottom Right
	glVertex3f(-.2, 0, .2);	// v2 Bottom Left
	glEnd();

	glBegin(GL_TRIANGLES); // 0, 1, 2, 3				//right
	glNormal3f(1, 0, 0);	// The surface normal
	glVertex3f(0,	1,	0);	// v0 
	glVertex3f(.2,	0,-.2);	// v1 
	glVertex3f(.2,	0, .2);	// v2 
	glEnd();

	glBegin(GL_TRIANGLES); // 0, 1, 2, 3				//back
	glNormal3f(0, 0, -1);	// The surface normal
	glVertex3f(0,	1,	0);	// v0 
	glVertex3f(-.2, 0,-.2);	// v1 
	glVertex3f(.2,	0,-.2);	// v2 
	glEnd();

	glBegin(GL_TRIANGLES); // 0, 1, 2, 3				//left
	glNormal3f(-1, 0, 0);	// The surface normal
	glVertex3f(0,	1,	0);	// v0 
	glVertex3f(-.2, 0, .2);	// v1 
	glVertex3f(-.2, 0,-.2);	// v2 
	glEnd();

		// Bottom Part
	glBegin(GL_TRIANGLES); // 0, 1, 2, 3				//front
	glColor3f(1, 0, 0);
	glVertex3f(0,  -1,	0);
	glVertex3f(-.2, 0, .2);
	glVertex3f(.2,	0, .2);
	glEnd();

	glBegin(GL_TRIANGLES); // 0, 1, 2, 3				//right
	glColor3f(1, 0, 0);
	glVertex3f(0,  -1,	0);
	glVertex3f(.2,	0, .2);
	glVertex3f(.2,	0,-.2);
	glEnd();

	glBegin(GL_TRIANGLES); // 0, 1, 2, 3				//back
	glColor3f(1, 0, 0);
	glVertex3f(0,  -1,	0);
	glVertex3f(.2,	0,-.2);
	glVertex3f(-.2, 0,-.2);
	glEnd();

	glBegin(GL_TRIANGLES); // 0, 1, 2, 3				//left
	glColor3f(1, 0, 0);
	glVertex3f(0,  -1,	0);
	glVertex3f(-.2, 0,-.2);
	glVertex3f(-.2, 0, .2);
	glEnd();

	glDisable(GL_LIGHTING); // this will ensure that other stuff we draw, such as the axis system will not be lit when drawn.
}
