#include "game.h"
#include "window.h"

extern GLfloat cubeAngleRotation;
extern int player_idx;
extern int item_idx;

void playerTimer(int v)
{
    player_idx++;
    if (player_idx == 6)
        player_idx -= 6;
    glutPostRedisplay();
    glutTimerFunc(100, playerTimer, v);
}

void itemTimer(int v)
{
    t_map* info = get_map_info();

    if (info->item_cnt == 0)
        return;

    item_idx++;
    if (item_idx == 8)
        item_idx -= 8;
    glutPostRedisplay();
    glutTimerFunc(100, itemTimer, v);
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
        glutTimerFunc(0, itemTimer, v);
    }
}