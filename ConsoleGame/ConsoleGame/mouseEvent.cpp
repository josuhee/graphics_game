#include "game.h"
#include "window.h"

void mouse(int button, int state, int x, int y) {
    Window* win = Window::getInstance();

    //기존 윈도우 크기
    float w = (float)win->getWidth();
    float h = (float)win->getHeight();

    //변환 좌표
    float nw = (x - w / 2.0) * (1.0 / (w / 2.0)) * (w / h);
    float nh = -(y - h / 2.0) * (1.0 / (h / 2.0));
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (nw >= -0.3 && nw <= 0.8)
        {
            if (nh >= -0.35 && nh <= -0.05)
            {
                //go game page
            }
            if (nh >= -0.75 && nh <= -0.45)
            {
                //End of the program
                exit(0);
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

void hover_mouse(int x, int y)
{
    Window* win = Window::getInstance();
    
    //기존 윈도우 크기
    float w = (float)win->getWidth();
    float h = (float)win->getHeight();
    float aspect = win->getAspect();
    float fixed = win->getFixed();

    //변환 좌표
    float nw;
    float nh;


    if ((float)w < (float)h * fixed) {
        nw = (x - w / 2.0) * (1.0 / (w / 2.0)) * fixed;
        nh = -(y - h / 2.0) * (1.0 / (h / 2.0)) / aspect * fixed;
    }
    else {
        nw = (x - w / 2.0) * (1.0 / (w / 2.0)) * aspect;
        nh = -(y - h / 2.0) * (1.0 / (h / 2.0));
    }


    printf("%.1f %.1f\n", nw, nh);

    if (win->getMode() == 1)
    {
        if (nw >= -0.3 && nw <= 0.8)
        {
            if (nh >= -0.35 && nh <= -0.05)
                solid[0] = true;
            else
                solid[0] = false;
            if (nh >= -0.75 && nh <= -0.45)
                solid[1] = true;
            else
                solid[1] = false;
        }
        else
            solid[0] = solid[1] = false;
    }
}

//GetCursorPos
//glfwGetCursorPos
//glfwSetInputMode