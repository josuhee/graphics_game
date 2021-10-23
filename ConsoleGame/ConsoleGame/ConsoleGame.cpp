#include "game.h"
#include "window.h"

static int num = 1;
GLfloat	currentAngleOfRotation = 0.0;
GLfloat	cubeAngleRotation = 0.0;

void reshape(GLint w, GLint h) {
    Window* win = Window::getInstance();
    GLfloat max_w;
    GLfloat max_h;
    GLfloat fixed = win->getFixed();

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    win->setWidth(w);
    win->setHeight(h);
    win->setAspect((float)w / h);
    if ((float)w < (float)h * fixed) {
        max_h = w / fixed;
        glViewport(0, (GLint)(h - max_h) / 2, w, (GLsizei)max_h);
    }
    else {
        max_w = fixed * h;
        glViewport((GLint)(w - max_w) / 2, 0, (GLsizei)max_w, h);
    }
    glOrtho(-1.0 * fixed, 1.0 * fixed, -1.0, 1.0, -1.0, 1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); //행렬초기화

    Font info{ -0.5, 0.0, 0.0, 300.0, 10.0 };

    if (num == 1)
        startPage();
    else
    {
        glPrint("Bye", info);
    }
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    //Get information of Window
    Window* win = Window::getInstance();

    //Window init function
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(550, 150);
    glutInitWindowSize(win->getWidth(), win->getHeight());
    glutCreateWindow("Spinning Square");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    
    //timer
    glutTimerFunc(100, cubeTimer, 0);
    
    //event
    glutKeyboardFunc(processNormalKey);
    glutSpecialFunc(processSpcialKey);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(hover_mouse);
    
    //loop
    glutMainLoop();
    return (0);
}