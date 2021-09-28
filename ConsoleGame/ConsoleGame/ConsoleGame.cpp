#include "game.h"

GLvoid drawBackground(GLvoid); 
GLvoid DrawTri(GLvoid);
GLvoid CubeMatrix(GLvoid);
GLvoid DrawScene(GLvoid);
GLvoid DrawText(GLvoid);

void main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(600, 300);
    glutInitWindowSize(300, 300);
    glutCreateWindow("Console Game");
    InitFont();
    glutDisplayFunc(DrawScene);
    glutKeyboardFunc(processNormalKey);
    glutMainLoop();
    atexit(KillFont);
}

GLvoid DrawScene(GLvoid)
{
    //background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //cube
    CubeMatrix();

    //text
    DrawText();

    //draw
    glFlush();
}

GLvoid DrawText(GLvoid)
{
    glColor4f(1.0, 1.0, 0.0, 1);
    glRasterPos2f(0.0f, 0.0f);
    glPrint("Hello World");
}

GLvoid CubeMatrix(GLvoid)
{
    glColor4f(1.0, 0.0, 1.0, 1);
    glPushMatrix();

    //회전할 각도, x, y, z 축?
    glRotatef(30, 1.0f, 1.0f, 1.0f);
    //glTranslatef(-0.6, 0.6, 0.0);
    glutWireCube(0.4);
    glPopMatrix();
}

GLvoid DrawTri(GLvoid)
{
    // change color of triangle
    glColor3f(0.4, 0.72, 0.1);

    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();
}