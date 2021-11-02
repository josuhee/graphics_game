#include "game.h"
#include "window.h"

extern GLfloat cubeAngleRotation;
extern int player_idx;

void playerTimer(int v)
{
    player_idx++;
    if (player_idx == 6)
        player_idx -= 6;
    glutPostRedisplay();
    glutTimerFunc(100, playerTimer, v);
}

void cubeTimer(int v)
{
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
    if (win->getMode() == 2)
    {
        glutTimerFunc(0, playerTimer, v);
    }
}