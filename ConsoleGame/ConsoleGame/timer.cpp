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
timer ���� ���̵��
��� ������ ����ͼ� �˻��ϱ�??


*/