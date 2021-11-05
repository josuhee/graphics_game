#include "game.h"

GLfloat cubeAngleRotation;
bool    solid[2] = { false, false };
extern int player_idx;

GLvoid          startPage()
{
    draw_img(2, { -1.6f, -1.0f }, { 1.6f, 1.0f });

    drawCude((float)-0.6, (float)-0.2, solid[0], cubeAngleRotation);
    drawCude((float)-0.6, (float)-0.6, solid[1], cubeAngleRotation);

    glLineWidth(4.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor4f(88.0 / 255.0f, 14.0f / 255.0f, 8.0f / 255.0f, 1.0f);
    drawRect({ -0.3f, -0.05f }, { 0.8f, -0.35f });
    drawRect({ -0.3f, -0.45f }, { 0.8f, -0.75f });
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    Font info{ -0.1f, -0.3f, 0.0f, 550.0f, 5.0f };
    glColor4f(1.0, 1.0, 1.0, 1.0);
    glPrint("START", info);

    Font info2{0.0f, -0.7f, 0.0f, 550.0f, 5.0f };
    glPrint("EXIT", info2);

    Font info3{ -0.7f, 0.3f, 0.0f, 250.0f, 5.0f };
    glColor4f(1.0, 1.0, 1.0, 1.0);
    glPrint("Game", info3);

    float x = -1.3f;
    float y = -0.7f;

    draw_img_player(player_idx, { x, y }, { x + 0.2f , y + 0.2f });
}