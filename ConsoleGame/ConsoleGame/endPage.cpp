#include "game.h"

GLfloat degree = 0.0f;
bool    solid_e[2] = { false, false };

GLvoid          endPage()
{
    glColor4f((GLfloat)(60.0 / 255.0), (GLfloat)(39.0 / 255.0), (GLfloat)(119.0 / 255.0), (GLfloat)1.0);
    drawRect({ -1.6f, -1.0f }, { 1.6f, 1.0f });

    drawCude((float)-0.6, (float)-0.2, solid_e[0], degree);
    drawCude((float)-0.6, (float)-0.6, solid_e[1], degree);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor4f((GLfloat)(254.0 / 255.0), (GLfloat)(222.0 / 255.0), (GLfloat)(236.0 / 255.0), (GLfloat)1.0);
    drawRect({ -0.3f, -0.05f }, { 0.8f, -0.35f });
    drawRect({ -0.3f, -0.45f }, { 0.8f, -0.75f });
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    Font info{ -0.1f, -0.3f, 0.0f, 550.0f, 5.0f };
    glColor4f(0.5, 1.0, 1.0, 1.0);
    glPrint("HOME", info);

    Font info2{ 0.0f, -0.7f, 0.0f, 550.0f, 5.0f };
    glColor4f(0.5, 1.0, 1.0, 1.0);
    glPrint("EXIT", info2);

    t_map* map = get_map_info();

    Font info3{ -0.7f, 0.3f, 0.0f, 250.0f, 5.0f };
    glColor4f(1.0, 1.0, 1.0, 1.0);
    if (map->clear)
        glPrint("Game Clear", info3);
    else
        glPrint("Game Over", info3);

}
