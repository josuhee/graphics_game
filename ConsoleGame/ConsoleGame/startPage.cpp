#include "game.h"

extern GLfloat cubeAngleRotation;
bool            solid[2] = { false, false };

GLvoid          startPage()
{
    glColor4f((GLfloat)(7.0 / 255.0), (GLfloat)(44.0 / 255.0), (GLfloat)(105.0 / 255.0), (GLfloat)1.0);
    drawRect({ -1.6f, -1.0f }, { 1.6f, 1.0f });

    drawCude((float)-0.6, (float)-0.2, solid[0], cubeAngleRotation);
    drawCude((float)-0.6, (float)-0.6, solid[1], cubeAngleRotation);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor4f((GLfloat)(254.0 / 255.0), (GLfloat)(222.0 / 255.0), (GLfloat)(236.0 / 255.0), (GLfloat)1.0);
    drawRect({ -0.3f, -0.05f }, { 0.8f, -0.35f });
    drawRect({ -0.3f, -0.45f }, { 0.8f, -0.75f });
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    Font info{ -0.1f, -0.3f, 0.0f, 550.0f, 10.0f };
    glColor4f(0.5, 1.0, 1.0, 1.0);
    glPrint("START", info);

    Font info2{0.0f, -0.7f, 0.0f, 550.0f, 10.0f };
    glColor4f(0.5, 1.0, 1.0, 1.0);
    glPrint("EXIT", info2);

    Font info3{ -0.7f, 0.3f, 0.0f, 250.0f, 10.0f };
    glColor4f(1.0, 1.0, 1.0, 1.0);
    glPrint("Game", info3);
}