#include "game.h"
#include "font.h"

GLvoid glPrint(const char* text, Font info)
{
    float size = info.getSize();

    glPushMatrix();
    glTranslatef(info.getX(), info.getY(), info.getZ());
    glScalef(1 / size, 1 / size, 1 / size);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(info.getBold());//±½±â
    for (int i = 0; text[i]; i++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
    glPopMatrix();
    glDisable(GL_LINE_SMOOTH);
    glDisable(GL_BLEND);
}

void     drawCude(float x, float y, bool flag, float degree)
{
    if (flag)
    {
        glColor4f(253.0f / 255.0f, 166.0f / 255.0f, 127.0f / 255.0f, 0.1f);
        glPushMatrix();
        glTranslatef(x, y, 0.0);
        glRotatef(degree, 1.0f, 1.0f, 1.0f);
        glutSolidCube(0.2);
        glPopMatrix();
    }

    glColor4f(88.0f / 255.0f, 14.0f / 255.0f, 8.0f / 255.0f, 1.0f);
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    //glLineWidth(4.0);//±½±â
    glRotatef(degree, 1.0f, 1.0f, 1.0f);
    glutWireCube(0.2);
    glPopMatrix();
}

void     drawRect(t_point_f p1, t_point_f p2)
{
    glBegin(GL_POLYGON);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p1.x, p2.y);
    glVertex2f(p2.x, p2.y);
    glVertex2f(p2.x, p1.y);
    glEnd();
}