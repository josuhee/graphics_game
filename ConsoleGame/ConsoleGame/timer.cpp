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

pair<int, int> p;
float e_dx = 0.0f, e_dy = 0.0f;
bool flag = true;

void enemyMoveUtilTimer(int v)
{
    t_map* info = get_map_info();

    if (v == 5)
    {
        e_dx = e_dy = 0.0f;
        info->enemy_x = p.first;
        info->enemy_y = p.second;
        flag = true;
        return;
    }
    flag = false;
    e_dx = (p.first - info->enemy_x) * 0.04f * v;
    e_dy = (info->enemy_y - p.second) * 0.04f * v;
    glutPostRedisplay();
    //적의 속도 조절하기
    glutTimerFunc(80, enemyMoveUtilTimer, v + 1);
}

void enemyMoveTimer(int v)
{
    Window* win = Window::getInstance();
    t_map* info = get_map_info();

    if (win->getMode() == 2)
    {
        if (flag)
        {
            p = search_player();
            glutTimerFunc(0, enemyMoveUtilTimer, 1);
            if (info->enemy_x == info->player_x && info->enemy_y == info->player_y)
                win->setMode(3);
            glutPostRedisplay();
        }
        glutTimerFunc(0, enemyMoveTimer, v);
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
        glutTimerFunc(1000, enemyMoveTimer, v);
    }
}