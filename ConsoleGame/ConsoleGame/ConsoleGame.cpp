#include "game.h"
#include "window.h"

//GLfloat	cubeAngleRotation = 0.0f;

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
    Window* win = Window::getInstance();

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); //행렬초기화

    if (win->getMode() == 1)
    {
        glBindTexture(GL_TEXTURE_2D, 0);
        startPage();
    }
    else if (win->getMode() == 2)
    {
        glBindTexture(GL_TEXTURE_2D, 0);
        gamePage();
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, 0);
        endPage();
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
    glutCreateWindow("Game");
    init_image();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    
    //timer
    glutTimerFunc(100, cubeTimer, 0);
    
    //event
    //glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    glutKeyboardFunc(processNormalKey);
    glutSpecialFunc(processSpcialKey);
    glutSpecialUpFunc(processSpecialKeyUp);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(hover_mouse);


    //loop
    glutMainLoop();
    return (0);
}