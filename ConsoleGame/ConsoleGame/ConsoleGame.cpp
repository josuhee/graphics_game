#include "game.h"

GLvoid drawBackground(GLvoid); 
void DoDisplay();
void seongele();

void main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(600, 300);
    glutInitWindowSize(300, 300);
    glutCreateWindow("Console Game");
    glutDisplayFunc(seongele);
    glutKeyboardFunc(processNormalKey);
    glutMainLoop();
}

void DoDisplay()
{
    // change background color
    glClearColor(1.0, 0.24, 0.5, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    // change color of triangle
    glColor3f(0.4, 0.72, 0.1);

    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();
}

void seongele() 
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor4f(1.0, 0.0, 1.0, 1);
    glPushMatrix();

    //회전할 각도, x, y, z 축?
    glRotatef(30, 1.0f, 1.0f, 1.0f);
    //glTranslatef(-0.6, 0.6, 0.0);
    glutWireCube(0.4);
    glPopMatrix();
    glFlush();
}

/*

GLvoid drawGameStart(GLvoid)
{
    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
    glFinish();
}
*/