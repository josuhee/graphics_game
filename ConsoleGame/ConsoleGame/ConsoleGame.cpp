#include "game.h"
#include "window.h"
#include <stdio.h>

static bool spinning = true;
static const int FPS = 60;
static GLfloat currentAngleOfRotation = 0.0;
static int num = 1;

void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    GLfloat aspect = (GLfloat)w / (GLfloat)h;
    if (w <= h) {
        glOrtho(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect, -1.0, 1.0);
    }
    else {
        glOrtho(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0, -1.0, 1.0);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); //행렬초기화

    if (num == 1)
    {
        glColor3f(1.0, 1.0, 0.0);
        glPushMatrix();
        glRotatef(currentAngleOfRotation, 1.0f, 1.0f, 1.0f);
        glutWireCube(0.4);
        glPopMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glPushMatrix();
        glTranslatef(0.5, 0.0, 0.5);
        glRotatef(100, 1.0f, 1.0f, 1.0f);
        glutWireCube(0.4);
        glPopMatrix();

        glColor3f(0.0, 1.0, 1.0);
        glRasterPos2f(0.0f, 0.0f);
        //glTranslatef(-0.6, 0.6, 0.0);
        glPrint("Hello");
    }
    else
    {
        glColor3f(0.0, 1.0, 1.0);
        glRasterPos2f(0.0f, 0.0f);
        //glTranslatef(-0.6, 0.6, 0.0);
        glPrint("Bye");
    }
    glutSwapBuffers();
}

// 타이머
// 사각형의 각도 변환 및 다시 그리기.
void timer(int v) {
    if (spinning) {
        currentAngleOfRotation += 1.0;
        if (currentAngleOfRotation > 360.0) {
            currentAngleOfRotation -= 360.0;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(10, timer, v);
}



int main(int argc, char** argv) {
    //Get information of Window
    Window* win = Window::getInstance();

    //Window init function
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(win->getWidth(), win->getHeight());
    glutCreateWindow("Spinning Square");
    glutReshapeFunc(reshape);
    InitFont();
    glutDisplayFunc(display);
    
    //timer
    glutTimerFunc(100, timer, 0);
    
    //event
    glutKeyboardFunc(processNormalKey);
    glutMouseFunc(mouse);
    
    //loop
    glutMainLoop();

    //free font
    atexit(KillFont);
    return (0);
}