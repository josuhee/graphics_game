#include "game.h"
#include "window.h"

extern GLfloat cubeAngleRotation;

void cubeTimer(int v) {
    Window* win = Window::getInstance();

    if (win->getMode() == 1)
    {
        cubeAngleRotation += 1.0;
        if (cubeAngleRotation > 360.0) {
            cubeAngleRotation -= 360.0;
        }
        glutPostRedisplay();

        glutTimerFunc(7, cubeTimer, v);

    }
}

/*
timer 관리 아이디어
헤더 정보를 끌어와서 검사하기??


*/