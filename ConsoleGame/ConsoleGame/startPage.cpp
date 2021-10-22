#include "game.h"

extern GLfloat cubeAngleRotation;
extern GLfloat currentAngleOfRotation;

bool            solid[2] = { false, false };

typedef struct   s_point {
    float x;
    float y;
}t_point;

static void    drawCude(float x, float y, bool flag)
{
    if (flag)
    {
        glColor4f(248 / 255.0, 94 / 255.0, 252 / 255.0, 0.5);
        glPushMatrix();
        glTranslatef(x, y, 0.0);
        glRotatef(cubeAngleRotation, 1.0f, 1.0f, 1.0f);
        glutSolidCube(0.2);
        glPopMatrix();
    }

    glColor4f(157 / 255.0, 7 / 255.0, 161 / 255.0, 1.0);
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    //glLineWidth(4.0);//±½±â
    glRotatef(cubeAngleRotation, 1.0f, 1.0f, 1.0f);
    glutWireCube(0.2);
    glPopMatrix();
}

static void    drawRect(t_point p1, t_point p2)
{
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glBegin(GL_POLYGON);
        glVertex2f(p1.x, p1.y);
        glVertex2f(p1.x, p2.y);
        glVertex2f(p2.x, p2.y);
        glVertex2f(p2.x, p1.y);
    glEnd();

    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}

GLvoid      startPage()
{
    glColor4f(7 / 255.0, 44 / 255.0, 105 / 255.0, 1.0);
    drawRect({ -1.6, -1.0 }, { 1.6, 1.0 });

    drawCude(-0.6, -0.2, solid[0]);
    drawCude(-0.6, -0.6, solid[1]);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor4f(254 / 255.0, 222 / 255.0, 236 / 255.0, 1.0);
    drawRect({ -0.3, -0.05 }, { 0.8, -0.35 });
    drawRect({ -0.3, -0.45 }, { 0.8, -0.75 });
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    Font info{ -0.1, -0.3, 0.0, 550.0, 10.0 };
    glColor4f(0.5, 1.0, 1.0, 1.0);
    glPrint("START", info);

    Font info2{0.0, -0.7, 0.0, 550.0, 10.0 };
    glColor4f(0.5, 1.0, 1.0, 1.0);
    glPrint("EXIT", info2);

    Font info3{ -0.7, 0.3, 0.0, 250.0, 10.0 };
    glColor4f(1.0, 1.0, 1.0, 1.0);
    glPrint("Game", info3);
}