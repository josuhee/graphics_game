﻿#include "game.h"
#include "window.h"
#include "font.h"
#include <stdio.h>

static bool spinning = true;
static const int FPS = 60;
static GLfloat currentAngleOfRotation = 0.0;
static int num = 1;

void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    GLfloat aspect = (GLfloat)w / (GLfloat)h;
    if (w <= h) {
        glOrtho(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect, -1.0, 1.0);
    }
    else {
        glOrtho(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0, -1.0, 1.0);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); //행렬초기화

    Font info{ -0.5, 0.0, 0.0, 300.0, 10.0 };

    if (num == 1)
    {
        glColor4f(1.0, 1.0, 0.5, 1.0);
        glPushMatrix();
        glRotatef(currentAngleOfRotation, 1.0f, 1.0f, 1.0f);
        glutSolidCube(0.4);
        glPopMatrix();

        glColor3f(1.0, 0.0, 1.0);
        glPushMatrix();
        glLineWidth(4.0);
        glRotatef(currentAngleOfRotation, 1.0f, 1.0f, 1.0f);
        glutWireCube(0.4);
        glPopMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glPushMatrix();
        glTranslatef(0.5, 0.0, 0.5);
        glRotatef(100, 1.0f, 1.0f, 1.0f);
        glutWireCube(0.4);
        glPopMatrix();

        glColor3f(0.5, 1.0, 1.0);
        glPrint("Hi", info);
    }
    else
    {
        glPrint("Bye", info);
    }
    glutSwapBuffers();
}

// 타이머
// 사각형의 각도 변환 및 다시 그리기.
void timer(int v) {
    if (spinning) {
        currentAngleOfRotation += 1.0;
        if (currentAngleOfRotation > 360.0) {
            currentAngleOfRotation -= 360.0;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(10, timer, v);
}



int main(int argc, char** argv) {
    //Get information of Window
    Window* win = Window::getInstance();

    //Window init function
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(win->getWidth(), win->getHeight());
    glutCreateWindow("Spinning Square");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    
    //timer
    glutTimerFunc(100, timer, 0);
    
    //event
    glutKeyboardFunc(processNormalKey);
    glutSpecialFunc(processSpcialKey);
    glutMouseFunc(mouse);
    
    //loop
    glutMainLoop();
    return (0);
}