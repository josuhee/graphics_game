#include "game.h"
#include "window.h"

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        //���� ���콺
        /*
        spinning = true;
        //������ ��ǥ
        printf("(%d, %d)\n", x, y);
        //��ȯ ��ǥ
        int w = 800;
        int h = 500;
        float nx = (float)(x - (float)w / 2.0) * (float)(1.0 / (float)(w / 2.0));
        float ny = -(float)(y - (float)h / 2.0) * (float)(1.0 / (float)(h / 2.0));
        printf("(%.1lf, %.1lf)\n\n", nx, ny);
        num = 1;
        */
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        //������ ���콺
        /*
        spinning = false;
        num = 2;
        */
    }
}

void hover_mouse(int x, int y)
{
    Window* win = Window::getInstance();
    
    //���� ������ ũ��
    float w = win->getWidth();
    float h = win->getHeight();

    //��ȯ ��ǥ
    float nw = (x - w / 2.0) * (1.0 / (w / 2.0));
    float nh = -(y - h / 2.0) * (1.0 / (h / 2.0));

    printf("%.1f %.1f\n", nw, nh);
}