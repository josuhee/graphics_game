#include "game.h"
#include "font.h"

GLvoid glPrint(const char* text, Font info)
{
    float size = info.getSize();

    glPushMatrix();
    glTranslatef(info.getX(), info.getY(), info.getZ());
    glScalef(1 / size, 1 / size, 1 / size);
    /*
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    */
    //glLineWidth(info.getBold());//±½±â
    for (int i = 0; text[i]; i++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
    glPopMatrix();
}