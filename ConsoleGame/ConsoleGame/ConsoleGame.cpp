#include "game.h"
#include <stdio.h>

static bool spinning = true;
static const int FPS = 60;
static GLfloat currentAngleOfRotation = 0.0;
static GLfloat currentAngleOfRotation2 = 0.0;

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

    glColor3f(1.0, 1.0, 0.0);
    glPushMatrix();
    glRotatef(currentAngleOfRotation, 1.0f, 1.0f, 1.0f);
    glutWireCube(0.4);
    glPopMatrix();

    glColor3f(0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(-0.1, 0.6, 0.0);
    glRotatef(currentAngleOfRotation2 + 10, 1.0f, 1.0f, 1.0f);
    glutWireCube(0.4);
    glPopMatrix();

    glColor3f(0.0, 1.0, 1.0);
    glRasterPos2f(0.0f, 0.0f);
    //glTranslatef(-0.6, 0.6, 0.0);
    glPrint("Hello");
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
    glutTimerFunc(5, timer, v);
}

void timer2(int v) {
    if (spinning) {
        currentAngleOfRotation2 += 1.0;
        if (currentAngleOfRotation2 > 360.0) {
            currentAngleOfRotation2 -= 360.0;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(1000 / FPS, timer2, v);
}


// mouse event
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        spinning = true;
        //윈도우 좌표
        printf("(%d, %d)\n", x, y);
        //변환 좌표
        int w = 800;
        int h = 500;
        float nx = (float)(x - (float)w / 2.0) * (float)(1.0 / (float)(w / 2.0));
        float ny = -(float)(y - (float)h / 2.0) * (float)(1.0 / (float)(h / 2.0));
        printf("(%.1lf, %.1lf)\n\n", nx, ny);
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        spinning = false;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Spinning Square");
    InitFont();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutTimerFunc(100, timer, 0);
    glutTimerFunc(100, timer2, 0);
    glutKeyboardFunc(processNormalKey);
    glutMouseFunc(mouse);
    glutMainLoop();
    atexit(KillFont);
}