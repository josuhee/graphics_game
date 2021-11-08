#include "game.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

/****************************
*  image init source file   *
*****************************/

GLuint  texID[5];
GLuint  playerID[6];
GLuint  itemID[8];
GLuint  enemyID[4];
int width, height;

// load image file
static unsigned char* LoadMeshFromFile(const char* texFile)
{
    FILE* fp = NULL;
    if (fopen_s(&fp, texFile, "rb")) {
        printf("ERROR : No %s. \n fail to bind texture\n", texFile);
        exit(1);
    }
    int channel;
    unsigned char* image = stbi_load_from_file(fp, &width, &height, &channel, 4);
    fclose(fp);
    return image;
}

static void init_image_util(char* filename, int n)
{
    unsigned char* bitmap;
    bitmap = LoadMeshFromFile(filename);
    glBindTexture(GL_TEXTURE_2D, texID[n]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap);
    glBindTexture(GL_TEXTURE_2D, 0);
    free(bitmap);
}

// texture, player animation image
static void init_image_player(char* filename, int n)
{
    unsigned char* bitmap;
    bitmap = LoadMeshFromFile(filename);
    glBindTexture(GL_TEXTURE_2D, playerID[n]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap);
    glBindTexture(GL_TEXTURE_2D, 0);
    free(bitmap);
}

// texture, item animation image
static void init_image_item(char* filename, int n)
{
    unsigned char* bitmap;
    bitmap = LoadMeshFromFile(filename);
    glBindTexture(GL_TEXTURE_2D, itemID[n]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap);
    glBindTexture(GL_TEXTURE_2D, 0);
    free(bitmap);
}

// texture, enemy animation image
static void init_image_enemy(char* filename, int n)
{
    unsigned char* bitmap;
    bitmap = LoadMeshFromFile(filename);
    glBindTexture(GL_TEXTURE_2D, enemyID[n]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap);
    glBindTexture(GL_TEXTURE_2D, 0);
    free(bitmap);
}

// init image
void init_image(void)
{
    stbi_set_flip_vertically_on_load(true); // 상하 반전

    // utils
    glEnable(GL_TEXTURE_2D);
    glGenTextures(4, &texID[0]);
    init_image_util((char*)"image/else/block.png", 0);
    init_image_util((char*)"image/else/exit.png", 1);
    init_image_util((char*)"image/else/sample.png", 2);
    init_image_util((char*)"image/else/over.png", 3);
    
    // player
    glEnable(GL_TEXTURE_2D);
    glGenTextures(6, &playerID[0]);
    init_image_player((char*)"image/player/player_0.png", 0);
    init_image_player((char*)"image/player/player_1.png", 1);
    init_image_player((char*)"image/player/player_2.png", 2);
    init_image_player((char*)"image/player/player_3.png", 3);
    init_image_player((char*)"image/player/player_4.png", 4);
    init_image_player((char*)"image/player/player_5.png", 5);

    // item
    glEnable(GL_TEXTURE_2D);
    glGenTextures(8, &itemID[0]);
    init_image_item((char*)"image/collect/collect_0.png", 0);
    init_image_item((char*)"image/collect/collect_1.png", 1);
    init_image_item((char*)"image/collect/collect_2.png", 2);
    init_image_item((char*)"image/collect/collect_3.png", 3);
    init_image_item((char*)"image/collect/collect_4.png", 4);
    init_image_item((char*)"image/collect/collect_5.png", 5);
    init_image_item((char*)"image/collect/collect_6.png", 6);
    init_image_item((char*)"image/collect/collect_7.png", 7);

    // enemy
    glEnable(GL_TEXTURE_2D);
    glGenTextures(4, &enemyID[0]);
    init_image_enemy((char*)"image/enemy/anim_0.png", 0);
    init_image_enemy((char*)"image/enemy/anim_1.png", 1);
    init_image_enemy((char*)"image/enemy/anim_2.png", 2);
    init_image_enemy((char*)"image/enemy/anim_3.png", 3);
}


/*************************
* Draw image function *
**************************/

void draw_img(int n, t_point_f p1, t_point_f p2)
{
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBindTexture(GL_TEXTURE_2D, texID[n]);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);      glVertex2f(p1.x, p1.y);
    glTexCoord2d(0.0, 1.0);      glVertex2f(p1.x, p2.y);
    glTexCoord2d(1.0, 1.0);      glVertex2f(p2.x, p2.y);
    glTexCoord2d(1.0, 0.0);      glVertex2f(p2.x, p1.y);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_BLEND);
}

void draw_img_player(int n, t_point_f p1, t_point_f p2)
{
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBindTexture(GL_TEXTURE_2D, playerID[n]);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);      glVertex2f(p1.x, p1.y);
    glTexCoord2d(0.0, 1.0);      glVertex2f(p1.x, p2.y);
    glTexCoord2d(1.0, 1.0);      glVertex2f(p2.x, p2.y);
    glTexCoord2d(1.0, 0.0);      glVertex2f(p2.x, p1.y);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_BLEND);
}

void draw_img_item(int n, t_point_f p1, t_point_f p2)
{
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBindTexture(GL_TEXTURE_2D, itemID[n]);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);      glVertex2f(p1.x, p1.y);
    glTexCoord2d(0.0, 1.0);      glVertex2f(p1.x, p2.y);
    glTexCoord2d(1.0, 1.0);      glVertex2f(p2.x, p2.y);
    glTexCoord2d(1.0, 0.0);      glVertex2f(p2.x, p1.y);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_BLEND);
}

void draw_img_enemy(int n, t_point_f p1, t_point_f p2)
{
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBindTexture(GL_TEXTURE_2D, enemyID[n]);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);      glVertex2f(p1.x, p1.y);
    glTexCoord2d(0.0, 1.0);      glVertex2f(p1.x, p2.y);
    glTexCoord2d(1.0, 1.0);      glVertex2f(p2.x, p2.y);
    glTexCoord2d(1.0, 0.0);      glVertex2f(p2.x, p1.y);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_BLEND);
}