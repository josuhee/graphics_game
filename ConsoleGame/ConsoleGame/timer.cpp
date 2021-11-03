#include "game.h"
#include "window.h"

//origin at startPage.cpp
extern GLfloat cubeAngleRotation;

//origin at endPage.cpp
extern GLfloat degree;

//origin at gamePage.cpp
extern int player_idx;
extern int item_idx;
extern int enemy_idx;

void cubeEndTimer(int v)
{
    Window* win = Window::getInstance();

    if (win->getMode() == 3)
    {
        degree += 1.0;
        if (degree > 360.0) {
            degree -= 360.0;
        }
        glutPostRedisplay();

        glutTimerFunc(7, cubeEndTimer, v);
    }
    else if (win->getMode() == 1)
    {
        glutTimerFunc(0, cubeTimer, v);
    }
}

void playerTimer(int v)
{
    Window* win = Window::getInstance();

    if (win->getMode() == 2)
    {
        player_idx++;
        if (player_idx == 6)
            player_idx -= 6;
        glutPostRedisplay();
        glutTimerFunc(100, playerTimer, v);
    }
    else if (win->getMode() == 3)
    {
        glutTimerFunc(0, cubeEndTimer, v);
    }
}

void itemTimer(int v)
{
    Window* win = Window::getInstance();
    t_map* info = get_map_info();

    if (win->getMode() != 2) return;
    if (info->item_cnt == 0) return;

    item_idx++;
    if (item_idx == 8)
        item_idx -= 8;
    glutPostRedisplay();
    glutTimerFunc(100, itemTimer, v);
}

void enemyTimer(int v)
{
    Window* win = Window::getInstance();

    if (win->getMode() == 2)
    {
        enemy_idx++;
        if (enemy_idx == 4)
            enemy_idx -= 4;
        glutPostRedisplay();
        glutTimerFunc(100, enemyTimer, v);
    }
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
        glutTimerFunc(0, enemyTimer, v);
    }
}