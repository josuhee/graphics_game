#include "game.h"
#include "window.h"

//윈도우 좌표를 opengl 좌표로 변경해주는 함수
static pair<float, float>   getPoint(int x, int y) {
    pair<float, float> result;
    Window* win = Window::getInstance();

    //기존 윈도우 크기
    float w = (float)win->getWidth();
    float h = (float)win->getHeight();
    float aspect = win->getAspect();
    float fixed = win->getFixed();

    //좌표 변환
    if ((float)w < (float)h * fixed) {
        result.first = (float)(x - w / 2.0) * (float)(1.0 / (w / 2.0)) * fixed;
        result.second = (float)-(y - h / 2.0) * (float)(1.0 / (h / 2.0)) / aspect * fixed;
    }
    else {
        result.first = (float)(x - w / 2.0) * (float)(1.0 / (w / 2.0)) * aspect;
        result.second = (float)-(y - h / 2.0) * (float)(1.0 / (h / 2.0));
    }

    return result;
}

extern bool startFlag;

//Mouse Click Event
void mouse(int button, int state, int x, int y) {
    Window* win = Window::getInstance();

    pair<float, float> p;
    p = getPoint(x, y);

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (win->getMode() == 1 || win->getMode() == 3)
        {
            if (p.first >= -0.3 && p.first <= 0.8)
            {
                //go game page
                if (p.second >= -0.35 && p.second <= -0.05)
                {
                    if (win->getMode() == 1)
                    {
                        win->setMode(2);
                        create_map();
                    }
                    else if (win->getMode() == 3)
                    {
                        startFlag = true;
                        win->setMode(1);
                    }
                }
                //End of the program
                if (p.second >= -0.75 && p.second <= -0.45)
                {
                    printf("\033[32mExit the Game\033[0m\n");
                    exit(0);
                }
            }
        }
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        //오른쪽 마우스
        /*
        spinning = false;
        num = 2;
        */
    }
}

extern bool solid[2];
extern bool solid_e[2];

//Mouse hover Event
void hover_mouse(int x, int y)
{
    Window* win = Window::getInstance();
    
    pair<float, float> p;
    p = getPoint(x, y);

    //Start Page
    if (win->getMode() == 1)
    {
        if (p.first >= -0.3 && p.first <= 0.8)
        {
            if (p.second >= -0.35 && p.second <= -0.05)
                solid[0] = true;
            else
                solid[0] = false;
            if (p.second >= -0.75 && p.second <= -0.45)
                solid[1] = true;
            else
                solid[1] = false;
        }
        else
            solid[0] = solid[1] = false;
    }

    //End Page
    if (win->getMode() == 3)
    {
        if (p.first >= -0.3 && p.first <= 0.8)
        {
            if (p.second >= -0.35 && p.second <= -0.05)
                solid_e[0] = true;
            else
                solid_e[0] = false;
            if (p.second >= -0.75 && p.second <= -0.45)
                solid_e[1] = true;
            else
                solid_e[1] = false;
        }
        else
            solid_e[0] = solid_e[1] = false;
    }
}