#include "game.h"

extern GLfloat cubeAngleRotation;

void cubeTimer(int v) {
    cubeAngleRotation += 1.0;
    if (cubeAngleRotation > 360.0) {
        cubeAngleRotation -= 360.0;
    }
    glutPostRedisplay();

    glutTimerFunc(10, cubeTimer, v);
}

/*
timer 관리 아이디어
헤더 정보를 끌어와서 검사하기??


*/