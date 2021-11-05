#include "game.h"

GLfloat degree = 0.0f;
bool    solid_e[2] = { false, false };
extern int enemy_idx;
extern int item_idx;

static GLvoid ClearPage(void)
{
    t_map* map = get_map_info();

    draw_img(2, { -1.6f, -1.0f }, { 1.6f, 1.0f });
    draw_img_item(item_idx, { 1.1f,-0.8f }, { 1.3f, -0.6f });

    glColor4f(1.0, 1.0, 1.0, 1.0);

    Font game{ -0.3f, 0.6f, 0.0f, 500.0f, 5.0f };
    glPrint("GAME", game);

    Font font{ -0.60f, 0.15f, 0.0f, 300.0f, 5.0f };
    glPrint("CLEAR", font);

    glLineWidth(4.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    drawRect({ -0.3f, -0.05f }, { 0.8f, -0.35f });
    drawRect({ -0.3f, -0.45f }, { 0.8f, -0.75f });
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glColor4f(1.0, 1.0, 1.0, 1.0);
    Font info{ -0.1f, -0.3f, 0.0f, 550.0f, 3.0f };
    glPrint("HOME", info);

    Font info2{ 0.0f, -0.7f, 0.0f, 550.0f, 3.0f };
    glPrint("EXIT", info2);
}

static GLvoid OverPage(void)
{
    t_map* map = get_map_info();

    draw_img(3, { -1.6f, -1.0f }, { 1.6f, 1.0f });

    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);

    Font game{ -0.3f, 0.6f, 0.0f, 500.0f, 5.0f };
    glPrint("GAME", game);
    
    Font font{ -0.52f, 0.15f, 0.0f, 300.0f, 5.0f };
    glPrint("OVER", font);

    draw_img_enemy(enemy_idx, { 0.9f, 0.3f }, { 1.3f, 0.7f });
    
    glLineWidth(4.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor4f(144.0f /255.0f, 28.0f / 255.0f, 28.0f / 255.0f, 1.0f);
    drawRect({ -0.3f, -0.05f }, { 0.8f, -0.35f });
    drawRect({ -0.3f, -0.45f }, { 0.8f, -0.75f });
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    Font info{ -0.1f, -0.3f, 0.0f, 550.0f, 3.0f };
    glPrint("HOME", info);

    Font info2{ 0.0f, -0.7f, 0.0f, 550.0f, 3.0f };
    glPrint("EXIT", info2);
}

GLvoid          endPage()
{
    t_map* map = get_map_info();

    if (map->clear)
    {
        ClearPage();
        glLineWidth(3.0f);
    }
    else
    {
        OverPage();
        glLineWidth(4.0f);
    }
    drawCude((float)-0.6, (float)-0.2, solid_e[0], degree);
    drawCude((float)-0.6, (float)-0.6, solid_e[1], degree);
}
