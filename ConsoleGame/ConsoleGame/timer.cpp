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
