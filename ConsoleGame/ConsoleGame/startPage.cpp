#include "game.h"

extern GLfloat cubeAngleRotation;
extern GLfloat currentAngleOfRotation;

GLvoid startPage()
{
    glColor4f(1.0, 1.0, 0.5, 1.0);
    glPushMatrix();
    glRotatef(cubeAngleRotation, 1.0f, 1.0f, 1.0f);
    glutSolidCube(0.4);
    glPopMatrix();

    glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
    glLineWidth(4.0);
    glRotatef(cubeAngleRotation, 1.0f, 1.0f, 1.0f);
    glutWireCube(0.4);
    glPopMatrix();

    glColor3f(0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.5);
    glRotatef(100, 1.0f, 1.0f, 1.0f);
    glutWireCube(0.4);
    glPopMatrix();

    Font info{ -0.5, 0.0, 0.0, 300.0, 10.0 };
    glColor3f(0.5, 1.0, 1.0);
    glPrint("Hi", info);
}